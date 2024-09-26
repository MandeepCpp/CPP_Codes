// std::try_lock() tries to lock all the lockable objects passed in it one by one in given order
// std::try_lock(m1,m2,m3,m4,m5....mn)
// on success this function returns -1 
// otherwise it will return 0-based mutex index number which it could not lock.
// if it fails to lock any of the mutex then it will release all the mutex it locked before
// if a call to try_lock in an exception, unlock is called for any locaked objects before rethrowing


#include<iostream>
#include<thread>
#include<chrono>
#include<mutex>

using namespace std;
int X=0;
int Y =0;
std::mutex m1,m2;

void dosomeWorkForSeconds(int seconds)
{
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

void incrementX(int &X, std::mutex& m, const char* desc)
{
    for(int i=0;i<5;i++)
    {
        m.lock();
        ++X;
        cout<<desc<<X<<endl;
        m.unlock();
        dosomeWorkForSeconds(2);
    }
}
void incrementY(int &Y, std::mutex& m, const char* desc)
{
    for(int i=0;i<5;i++)
    {
        m.lock();
        ++Y;
        cout<<desc<<Y<<endl;
        m.unlock();
        dosomeWorkForSeconds(2);
    }
}

void consumeXY()
{
    int useCount=5;
    int XplusY=0;
    while(1)
    {
        int lockResult = std::try_lock(m1,m2);
        if(lockResult==-1)
        {
            if(X!=0 && Y!=0)
            {
                --useCount;
                XplusY =XplusY + X+Y;
                X=0;Y=0;
                cout<<"XplusY "<<XplusY<<endl;
            }
            m1.unlock();
            m2.unlock();
            if(useCount==0)
                break;
        }
    }
}

int main()
{
    std::thread t1(incrementX,std::ref(X),std::ref(m1),"X");
    std::thread t2(incrementY,std::ref(Y),std::ref(m2),"Y");
    std::thread t3(consumeXY);



    t1.join();
    t2.join();
    t3.join();

    return 0;
}
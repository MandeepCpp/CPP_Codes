#include<iostream>
#include <thread>
#include <mutex>
#include <vector>
#include<memory>
using namespace std;

std::mutex m1;

// it creates objects for you(client), rather you initiating object directly
// FDP is used for separating object creation logic from the main client code
// for getting new object, we can call factory method and it returns the desired object
class Library
{
    public:
    virtual void callLibrary()=0;
    virtual bool DecodeFrame(int,float)=0;
    virtual ~Library(){}
};

class CUDA : public Library
{
    public:
    void callLibrary();
    bool DecodeFrame(int x,float f) override
    {
        x= 20;
        f=20.5;
        cout<<"CUDA has " <<x<< "and" << f<<endl;
        return true;
    }
};
class FFMpeg : public Library
{
    public:
    void callLibrary();
    bool DecodeFrame(int x,float f) override
    {
        x= 10;
        f=10.5;
        cout<<"FFMpeg has " <<x<< "and" << f<<endl;
        return true;
    }
};


void CUDA :: callLibrary()
{
    cout<<"creating cuda"<<endl;
    
    
}
void FFMpeg :: callLibrary()
{
    cout<<"creating ffmepg"<<endl;
}


class LibraryFactory
{
    public:
    static std::unique_ptr<Library> getLibrary(int vehicleType);
};

// only i need to change this part of code in future, client code will not change
// when we have similiar behaviour or closely related and encapsulate the creation process, then we use 
std::unique_ptr<Library> LibraryFactory:: getLibrary(int vehicleType)
{
    if(vehicleType==1)
    {
        return std::make_unique<CUDA>();
    }
   else if(vehicleType==0)
    {
        return std::make_unique<FFMpeg>();
    }
    else
    {
        cout<<"this type of vehicle is not created yet"<<endl;
    }

    return nullptr;
}

bool isCUDAAvailable()
{
    int cuda =2;
    if(cuda==1)
    {
        return true;
    }

    return false;
}
void CreateAndUseLibrary(int type)
{
    auto library = LibraryFactory::getLibrary(type);
    if(library)
    {
        std::lock_guard<mutex> lock (m1);
        library->callLibrary();
        library->DecodeFrame(0,0.0);

    }
}
int main()
{
   int input = isCUDAAvailable();

    // Vector to hold threads
    std::vector<std::thread> threads;

    // Create three threads with potentially different library types
    threads.emplace_back(CreateAndUseLibrary, input); // First thread
    threads.emplace_back(CreateAndUseLibrary, input); // Second thread
    threads.emplace_back(CreateAndUseLibrary, input); // Third thread

    // Join threads
    for (auto& thread : threads) {
        thread.join();
    }

    return 0;
}
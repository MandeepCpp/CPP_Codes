#include<iostream>
#include<list>
using namespace std;

class ISubscriber
{
    public:
    virtual void getnotify(string msg)=0;
};

class User : public ISubscriber
{
    private:
    int userId;
    public:
    User(int UId)
    {
        this->userId=UId;
    }
    void getnotify(string msg)
    {
        cout<<"User " <<userId << " Recevied "<< msg << endl;
    }
};

class Group
{
    private:
    list<ISubscriber*> users;
    public:
    void subscribe(ISubscriber* user)
    {
        users.push_back(user);
    }
    void unsubscribe(ISubscriber* user)
    {
        users.remove(user);
    }
    void notify(string msg)
    {
        for(auto user:users)
        {
            user->getnotify(msg);
        }
    }
};

int main()
{
   Group* group = new Group();

   User* user1 = new User(1);
   User* user2 = new User(2);
   User* user3 = new User(3);

    group->subscribe(user1);
    group->subscribe(user2);
    group->subscribe(user3);

    group->notify("new message");

    group->unsubscribe(user1);

    group->notify("new new message");

    return 0;
}
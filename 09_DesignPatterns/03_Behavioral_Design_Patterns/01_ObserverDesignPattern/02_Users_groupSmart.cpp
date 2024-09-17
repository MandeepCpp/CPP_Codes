#include <iostream>
#include <list>
#include <memory>
#include <string>
using namespace std;

class ISubscriber
{
public:
    virtual void getnotify(const string& msg) = 0;
    virtual ~ISubscriber() = default;
};

class User : public ISubscriber
{
private:
    int userId;

public:
    User(int UId)
    {
        this->userId = UId;
    }
    void getnotify(const string& msg) override
    {
        cout << "User " << userId << " Recevied " << msg << endl;
    }
};

class Group
{
private:
    list<weak_ptr<ISubscriber>> users;  // Use weak_ptr to avoid circular references

public:
    void subscribe(const shared_ptr<ISubscriber>& user)
    {
        users.push_back(user);
    }
    void unsubscribe(const shared_ptr<ISubscriber>& user)
    {
        users.remove_if([&user](const weak_ptr<ISubscriber>& weakUser) {
            auto sharedUser = weakUser.lock();
            return sharedUser == user;
        });
    }
    void notify(const string& msg)
    {
        for (const auto& weakUser : users)
        {
            if (auto user = weakUser.lock())
            {
                user->getnotify(msg);
            }
        }
    }
};

int main()
{
    auto group = make_shared<Group>();

    auto user1 = make_shared<User>(1);
    auto user2 = make_shared<User>(2);
    auto user3 = make_shared<User>(3);

    group->subscribe(user1);
    group->subscribe(user2);
    group->subscribe(user3);

    group->notify("new message");

    group->unsubscribe(user1);

    group->notify("new new message");

    return 0;
}
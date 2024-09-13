#include<iostream>
#include<memory>
using namespace std;


int main()
{
    //C++14
    auto ptr1 = std::make_unique<int>(50);

    std::unique_ptr<int> ptr2 (new int(15));
    auto lambda = [ptr3 = std::move(ptr2)]()
    {
        if(ptr3)
        {
            cout<<"value inside unique ptr : "<< *ptr3<<endl;
        }
        else{
            cout<<"no value"<<endl;
        }
    };

    lambda();

    // unique ptr is now owned by lambda and cannot accessed here;
    //cout<< *ptr2<<endl;
    return 0;
}
// template, factorial function

#include<iostream>
using namespace std;

template<typename T>
class myFact
{
    public:
    static T compute(T n)
    {
        T result=1;
        for(int i=1;i<=n;i++)
        {
            result *=i;
        }
        return result;
    }
};
int main()
{
    int fact_int = myFact<int>::compute(3);
    cout<<fact_int<<endl;

    unsigned long long fact_ull = myFact<unsigned long long>::compute(25);
    cout<<fact_ull<<endl;
    return 0;
}
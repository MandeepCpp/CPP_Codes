#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>

using namespace std;



void primeNumber(int n)
{
    int count=0;
    for(int i=1;i*i<=n;i++)         // start with 1 to avoid divison with 0
    {
        if(n%i==0)
        {
            count++;
            if((n/i)!=i)
            {
                count++;
            }
        }
    }

    if(count==2)
    {
        cout<<"yes it is prime"<<endl;
    }
    else
    {
        cout<<"no it is not prime"<<endl;
    }
}






int main()
{
     int n1=7;
     primeNumber(n1);   

     int n2=14;
     primeNumber(n2);

     return 0;
}
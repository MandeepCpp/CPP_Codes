#include<iostream>
using namespace std;

int * fun1()
{
     int arr[3] = {10,20,30};
    return arr;
} // runtime warning address of local variable 'arr' returned
int * fun2()
{
    static int arr[3] = {1,2,3};
    return arr;
}
int * fun3()
{
    int * arr = new int[3];
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    return arr;
}
int main()
{
    // int *myarr1 = fun1();
    // cout<<myarr1[0]<<endl;
    // cout<<myarr1[1]<<endl;
    // cout<<myarr1[2]<<endl;

    int *myarr2 = fun2();
    cout<<myarr2[0]<<endl;
    cout<<myarr2[1]<<endl;
    cout<<myarr2[2]<<endl;

    int *myarr3 = fun3();
    cout<<myarr3[0]<<endl;
    cout<<myarr3[1]<<endl;
    cout<<myarr3[2]<<endl;
    return 0;
}
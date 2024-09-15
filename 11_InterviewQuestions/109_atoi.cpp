#include<stdio.h>
#include<iostream>

using namespace std;

int myAtoi(char * ch)
{
    int res =0;
    int sign =1;
    int i =0;

    if (ch[0]=='-')
    {
        sign=-1;
        i++;
    }

    for(;ch[i]!='\0';i++)
    {
        res =res*10 + ch[i] -'0';
    }


    return sign*res;



}
int main()
{
    char str1[] = "-2185";

    int val = myAtoi(str1);
    cout<<val;

    return 0;
}
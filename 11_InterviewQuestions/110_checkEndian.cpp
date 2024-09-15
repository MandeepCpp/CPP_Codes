#include<iostream>

int main()
{
    unsigned int i =1;
    char*c = (char*)(&i);

    if(*c)
        std::cout<<"Little Endian"<<std::endl;
    else
        std::cout<<"Big Endian"<<std::endl;

    unsigned char ch = 150;
    for(unsigned int i=0;i<ch*2;i++)
    {
        std::cout<<i<<std::endl;
    }
}
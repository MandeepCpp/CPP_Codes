#include<iostream>
#include<vector>
using namespace std;
int main()
{
   std::vector<int> vec;
vec.push_back(10);
try{
   cout<<vec.at(1)<<endl;
}
catch(std::out_of_range &e)
{
    cout<<"out of Range access"<< e.what()<<endl;
}
catch(...)
{
    cout<<"Some exception"<<endl;
}

   cout<<"Hello"<<endl;


    return 0;
}
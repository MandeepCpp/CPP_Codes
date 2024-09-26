#include<iostream>
#include<vector>
using namespace std;
int main()
{
    std::vector<int> vec;
    vec.push_back(10);

try{
    //throw 1;
    //throw 1.5;
    //throw 1.4f;
    throw 'M';
    //throw "Throwing a string";    
     throw std::string("Mandeep");

}
catch(const int& e)
{
    cout<<"Int exception "<<e<<endl;
}
catch(const double& e)
{
    cout<<"double exception "<<e<<endl;
}
catch(const float& e)
{
    cout<<"Float exception "<<e<<endl;
}
catch(const char& e)
{
    cout<<"char exception "<<e<<endl;
}
catch(const char*& e)
{
    cout<<"char [] exception "<<e<<endl;
}
catch(const string& e)
{
    cout<<"string exception "<< e<<endl;
}
catch(...)
{
    cout<<"Some exception "<<endl;
}

   cout<<"Hello"<<endl;
    return 0;
}
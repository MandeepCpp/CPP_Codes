#include<iostream>
#include<set>
using namespace std;
/*
Given a string s, find the length of the longest 

substring

without repeating characters.

abcabcbb  = 3

mmandeep


 


*/


int longString(const string& str)
{

std::set<char> s;
int maxi = 0;

int i=0;
int j=0;

                                            // pqrababmzxy
                                            //     i
                                            //         




    for(int i =0;i<str.length();i++)
    {
        if(s.find(str[i])==s.end())  // pqrababmzxy
        {
            s.insert(str[i]);
        }
        else
        {
            int Cusize = s.size();
            s.clear();
            maxi = std::max(maxi,Cusize);
            continue;            

        }
        
            


        return maxi;

    }

    
}
int main()
{
    
    return 0;
}



// 1,6,3,2,8,9
// 1.2.3.6.8.9.

int arr[100]

int n  = vec.size()
std::sort(vec.begin(),vec.end());            nlogn
int m = 0;
if(n%2==0)
 m= (vec[(vec.size()/2)] + vec[(vec.size()/2)+1] )/2
else
m  = (vec[(vec.size()/2)]);


 1,2,3,4,5
 6,7,8,9



 10,5,3,2

                        1,2,3,4,5,10,20,1,0,3
                        0,1,1,2,3,4
                        min heap  = 5,4,5,10,20
                        max heap  = 2,1,1,0

                        if ma

                        2nlogn



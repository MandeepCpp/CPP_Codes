#include<iostream>
#include<vector>
using namespace std;

#define MAX(a,b) a>b?a:b
void f()
{
    int * x = (int*)malloc(10*sizeof(int));
    x[450]=90;
    cout<<x[450]<<endl; // undefined behaviour
    free(x);
}
int main()
{
   int a =10;
   int *ptr = &a;
   cout<<++a<<"  :  "<<&a<<endl;
   cout<<ptr++<<endl;
   cout<<ptr<<endl;

   int c = MAX(1-99,2-50);
   cout<<c<<endl;

   //day9
   f();

//    unsigned char var =0;
//    for(char x=0;x<=255;x++)
//    {
//     printf("%d",var);
//    }

    // define an vector, insert 10 values, and print all the  values
    std::vector<int> vec;
    for(int i=0;i<10;i++)
    {
        vec.push_back(i*10);
    }
    for(const auto& v:vec)
    {
        cout<<v<<" ";
    }
    cout<<endl;


    return 0;
}
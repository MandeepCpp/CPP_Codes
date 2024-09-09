// implementation Array as an Abstract Data type

#include <iostream>
#include<stdio.h>
#include <stdlib.h>

using namespace std;

struct myArray
{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct myArray *arr, int tSize, int uSize)
{
    arr->total_size = tSize;
    (*arr).used_size = uSize;

    (*arr).ptr = (int *)malloc(tSize * sizeof(int));
   cout<<"Array created"<<endl;
}

void Setvalue(struct myArray *arr,int n)
{
    
    for (int i = 0; i < arr->used_size; i++)
    {
       (arr->ptr)[i]=n;
       n+=10;
    }
}

int insertValue(struct myArray *arr,int index,int value)
{
     if(arr->used_size>=arr->total_size)
        return -1;
    for(int i = arr->used_size-1;i>=index;i--)
    {
        (arr->ptr)[i+1] = (arr->ptr)[i];
    }
    (arr->ptr)[index] = value;
    
    return 1;
}
int deleteValue(struct myArray *arr,int index)
{
     if(index>=arr->used_size)
        return -1;
        int temp = (arr->ptr)[index];
    for(int i = index;i<arr->used_size-1;i++)
    {
        (arr->ptr)[i] = (arr->ptr)[i+1];
    }

    
    return temp;
}
void show(struct myArray *arr)
{
    for (int i = 0; i < arr->used_size; i++)
    {
        cout<<(arr->ptr)[i]<<" ";
    }
    cout<<endl;
}

int linearSerach(struct myArray *arr, int element)
{
    for(int i =0;i<=arr->used_size;i++)
    {
        if((arr->ptr)[i]==element)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    struct myArray marks;
    createArray(&marks, 100, 10);
    Setvalue(&marks,10);
    show(&marks);
    cout<<marks.total_size<<" "<<marks.used_size<<endl;


    int res = insertValue(&marks,3,35);
    if(res==1)
    {
    marks.used_size+=1;
    show(&marks);
    }
    cout<<marks.total_size<<" "<<marks.used_size<<endl;

    int deletedElement = deleteValue(&marks,2);
    if(deletedElement!=-1)
    {
    marks.used_size-=1;
    show(&marks);
    cout<<"deleted Item "<<deletedElement<<endl;
    cout<<marks.total_size<<" "<<marks.used_size<<endl;
    }

    int LinSearch = linearSerach(&marks,30);
    if(LinSearch!=-1){
        cout<<"Element "<<30 <<" "<< "found at "<< LinSearch<<endl;}
    else
    {
        cout<<"Element "<<30 <<" "<<"not found"<<endl;
    }

    LinSearch = linearSerach(&marks,40);
    if(LinSearch!=-1){
        cout<<"Element "<<40 <<" "<< "found at "<< LinSearch<<endl;}
    else
    {
        cout<<"not found"<<endl;
    }




}

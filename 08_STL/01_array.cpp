// std::array

// syntax : std::array<T,N> arr;
// eg : std::array<int,10> arr;
// std::array is a container that encapsulates fixed size arrays.
// array size is needed at compile time
// 


#include<iostream>
#include<array>

int main()
{
    std::array<int, 5> arr = {12,66,5,8,3};
    std::array<int, 5> arr1{12,66,5,8,3};

    std::cout<<arr.at(3)<<std::endl;
    //std::cout<<arr.at(6)<<std::endl; // will give error with exception , it is safe
    //std::cout<<arr[6]<<std::endl;  // will not throw an error and give garbage value

    std::cout<<arr.data()<<std::endl;  // will return pointer to arr

    arr.fill(10);
    std::cout<<arr.at(3)<<std::endl;


    return 0;
}
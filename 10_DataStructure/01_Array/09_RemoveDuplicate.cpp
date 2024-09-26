#include <iostream>
#include <vector>
#include<unordered_set>
using namespace std;

int removeDuplicate(int arr[], int size)    // for sorted arr
{
    int i = 0;
    vector<int> vec;
    for (int j = 1; j < size; j++)
    {
        if (arr[j] != arr[i])
        {
            arr[i + 1] = arr[j];
            i++;
        }
        else
        {
            vec.push_back(arr[j]);
        }
    }

    cout<<"duplicate"<<endl;
    for(const auto&e:vec)
    {
        cout<<e<<" ";
    }
    cout<<endl;
    return i + 1;
}

std::vector<int> removeDuplicates(const std::vector<int>& arr) {     // for unsorted arr
    std::unordered_set<int> seen;
    std::vector<int> result;

    for (int num : arr) {
        if (seen.find(num) == seen.end()) {
            seen.insert(num);
            result.push_back(num);
        }
    }

    return result;
}
int main()
{
    // int arr1[]={0,1,1,2,2,2,3,3,3,3,4,4,4,4,4,5,5,5,5,5,5,6,6,6,6,6,6,7,7,7,7,8};
    int arr1[] = {6,5,3,2,4,2,5,9,74,5,3,14,4,7,6,1,4,2};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "before" << endl;
    for (auto &e : arr1)
    {
        cout << e << " ";
    }
    cout << endl
         << "after" << endl;
    int newsize = removeDuplicate(arr1, size1);
    for (int i = 0; i < newsize; i++)
    {
        cout << arr1[i] << " ";
    }
    
    return 0;
}
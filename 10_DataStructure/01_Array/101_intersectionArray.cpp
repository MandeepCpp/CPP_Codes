#include <iostream>
#include <set>
#include <vector>
using namespace std;

void intersectionArrayOptimal(int arr1[], int arr2[], int size1, int size2)
{
    int i = 0;
    int j = 0;
    vector<int> vec;
    while (i < size1 && j < size2)
    {
        if(arr1[i]<arr2[j])
        {
            i++;
        }
        else if(arr1[i]>arr2[j])
        {
            j++;
        }
       else
        {
            if (vec.size() == 0 || vec.back() != arr1[i])
            {
                vec.push_back(arr2[j]);
                i++;j++;
            }
        }
        
    }

    for (auto &e : vec)
    {
        cout << e << " ";
    }
}

int main()
{
    int arr1[] = {1, 3, 4, 5, 6, 8, 9};
    int arr2[] = {2, 3, 5, 5, 6, 8, 9};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    intersectionArrayOptimal(arr1, arr2, size1, size2);

    return 0;
}
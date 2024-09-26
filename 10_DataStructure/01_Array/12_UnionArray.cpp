#include <iostream>
#include <set>
#include <vector>
using namespace std;

void unionArray(int arr1[], int arr2[], int size1, int size2)
{
    set<int> s;
    for (int i = 0; i < size1; i++)
    {
        s.insert(arr1[i]);
    } // nlogn
    for (int i = 0; i < size2; i++)
    {
        s.insert(arr2[i]);
    } // nlogn
    int n = s.size();
    int arr[n];
    int i = 0;
    for (auto &e : s)
    {
        arr[i++] = e;
    } // 2n
    for (auto &e : arr)
    {
        cout << e << " ";
    }
}
void unionArrayOptimal(int arr1[], int arr2[], int size1, int size2)
{
    int i = 0;
    int j = 0;
    vector<int> vec;
    while (i < size1 && j < size2)
    {
        if (arr1[i] <= arr2[j])
        {
            if (vec.size() == 0 || vec.back() != arr1[i])
            {
                vec.push_back(arr1[i]);
            }
            i++;
        }
        else
        {
            if (vec.size() == 0 || vec.back() != arr2[j])
            {
                vec.push_back(arr2[j]);
            }
            j++;
        }
    }
    while (i < size1)
    {
        if (vec.size() == 0 || vec.back() != arr1[i])
        {
            vec.push_back(arr1[i]);
        }
        i++;
    }
    while (j < size2)
    {
        if (vec.size() == 0 || vec.back() != arr2[j])
        {
            vec.push_back(arr2[j]);
        }
        j++;
    }

    for (auto &e : vec)
    {
        cout << e << " ";
    }
}

int main()
{
    int arr1[] = {1,3,4,5,6,8,9};
    int arr2[] = {2, 3, 5, 5, 6, 8, 9};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    unionArray(arr1, arr2, size1, size2);
    cout<<endl;
    unionArrayOptimal(arr1, arr2, size1, size2);

    return 0;
}
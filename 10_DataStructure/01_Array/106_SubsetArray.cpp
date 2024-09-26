#include <iostream>
#include <algorithm>

using namespace std;
bool subsetarray(int arr1[], int arr2[], int len1, int len2)
{
    int i = 0;
    int j = 0;
    if (len1 < len2)
        return false;

    sort(arr1, arr1 + len1);
    sort(arr2, arr2 + len2);

    while (i < len1 && j < len2)
    {
        if (arr1[j] < arr2[i])
        {
            j++;
        }
        else if (arr1[j] == arr2[i])
        {
            j++;
            i++;
        }
        else if (arr1[j] > arr2[i])
        {
            return false;
        }
    }
    return (i < len2) ? false : true;
}
int main()
{
    int arr1[] = {11, 1, 13, 21, 3, 7};
    int arr2[] = {11, 3, 7, 1};
    int len1 = sizeof(arr1) / sizeof(int);
    int len2 = sizeof(arr2) / sizeof(int);
    bool res = subsetarray(arr1, arr2, len1, len2);

    cout << "Subset: " << res << endl;
    return 0;
}
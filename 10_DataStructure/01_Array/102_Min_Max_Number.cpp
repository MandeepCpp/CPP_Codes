#include <iostream>

using namespace std;
int *findMinMax(int arr[], int len)
{
    int max, min, i;
    int *res = new int[2];
    if (len % 2 == 0)
    {
        if (arr[0] > arr[1])
        {
            max = arr[0];
            min = arr[1];
        }
        else
        {
            max = arr[1];
            min = arr[0];
        }
        i = 2;
    }
    else
    {
        max = arr[0];
        min = arr[0];
        i = 1;
    }

    while (i < len - 1)
    {
        if (arr[i] > arr[i + 1])
        {
            if (arr[i] > max)
                max = arr[i];
            if (arr[i + 1] < min)
                min = arr[i + 1];
        }
        else
        {
            if (arr[i + 1] > max)
                max = arr[i + 1];
            if (arr[i] < min)
                min = arr[i];
        }
        i += 2;
    }
    res[0] = max;
    res[1] = min;
    return res;
}
int main()
{
    int arr[] = {4, 3, 7, 9, 5, 1, 5, 7, 5, 6, 8, 4};
    int len = sizeof(arr) / sizeof(int);

    int *res = findMinMax(arr, len);

    cout << "Max: " << res[0] << endl;
    cout << "Min: " << res[1] << endl;
    return 0;
}
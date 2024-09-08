#include <iostream>
using namespace std;

bool reverseNumber(int n)
{
    int temp = n;

    int sum = 0;

    while (n != 0)
    {
        sum = sum * 10 + n % 10;
        n /= 10;
    }
    if (sum == temp)
        return true;
    return false;
}

int main()
{
    cout << reverseNumber(1234) << endl;
    cout << reverseNumber(46500) << endl;
    cout << reverseNumber(12121) << endl;
    return 0;
}
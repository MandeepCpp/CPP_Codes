#include<iostream>
using namespace std;

class myInt
{
    int var;
public:
    myInt() {}
    myInt(int x): var(x) {}

    void printvalue() {
        cout << " : " << var << endl;
    }

    myInt& operator++() {
        cout<<"pre"<<endl;
        ++var;
        return *this;
    }

    myInt operator++(int dummy) {
         cout<<"post"<<endl;
        myInt temp = *this;
        var++;
        return temp;
    }
};

int main()
{
    myInt b(50);
    (b++).printvalue(); // Corrected incomplete statement
    (++b).printvalue(); // Corrected incomplete statement
    return 0;
}

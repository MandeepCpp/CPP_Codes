#include <iostream>
#include<vector>
using namespace std;

class A {
  public:
  A() { cout << "In constructor of A" << endl; }
  ~A() { cout << "In destructor of A" << endl; }
};

class B {
  public:
  B() { cout << "In constructor of B" << endl; }
  ~B() { cout << "In destructor of B" << endl; }
};

int main() {
    std::vector<int> vec;
    vec.push_back(10);
  try {    
    cout << "In try block" << endl;
    cout<<vec.at(1)<<endl;
    A a;
    B b;
    // destructor will be in reverse order
    throw("Exception thrown in try block of main()");
  }
  catch (const char* e) {
    cout << "Exception: " << e << endl;
  }
  catch (...) {
    cout << "Some exception caught in main()" << endl;
  }

  cout << "Resume execution of main()" << endl;
}
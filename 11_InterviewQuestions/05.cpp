// philips 1
// create class

// RAII

/*
RAII (Resource Acquisition Is Initialization) is a programming idiom used in C++
to manage resources such as memory, file handles, and network sockets.
The main idea behind RAII is to tie the lifespan of resources to the lifespan of objects,
ensuring that resources are properly released when objects go out of scope.
This is achieved by acquiring resources in a constructor and releasing them in a destructor.

Here's a breakdown of how RAII works:

Resource Acquisition in Constructor:
Resources are acquired (e.g., memory allocation, opening a file) when an object is created.
This ensures that resources are available and ready for use as soon as the object is constructed.

Resource Release in Destructor:
Resources are released (e.g., memory deallocation, closing a file) when the object goes out of scope and its destructor is called.
This ensures that resources are properly cleaned up, preventing resource leaks.

Advantages of RAII
Automatic Resource Management:
Resources are automatically managed by objects, reducing the risk of resource leaks.
Exception Safety:
RAII ensures that resources are properly released even in the presence of exceptions,
improving the robustness of the code.
Simplified Code: RAII abstracts resource management details, leading to cleaner and more maintainable code.

*/
#include <iostream>
#include <fstream>
using namespace std;

class Filehandler
{

    std::ofstream file;

public:
    Filehandler(const string &filename)
    {
        file.open(filename);
        
        if (!file.is_open())
        {
            throw std::runtime_error("Failed to open file");
        }
    }
    ~Filehandler()
    {
        if (file.is_open())
        {
            file.close();
        }
    }

    void write(const std::string &data)
    {
        if (file.is_open())
        {
            file << data;
        }
    }
};
int main()
{
    try
    {
        Filehandler fh("sample.txt");
        fh.write("Hello,RAII");
    }
    catch (const std::exception &e)
    {
        cout << e.what() << endl;
    }

    return 0;
}
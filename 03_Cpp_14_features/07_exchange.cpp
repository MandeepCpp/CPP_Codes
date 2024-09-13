#include <iostream>
#include <utility> // for std::exchange
#include <memory>

using namespace std;
class MyClass
{
private:
    int value_;
    std::unique_ptr<int> ptr_;

public:
    MyClass(int value, int ptrValue)
        : value_(value), ptr_(std::make_unique<int>(ptrValue)) {}

    
    // Delete copy constructor and copy assignment operator
    MyClass(const MyClass &) = delete;
    MyClass &operator=(const MyClass &) = delete;

    // Move constructor
    MyClass(MyClass &&other) noexcept
        : value_(std::exchange(other.value_, 0)),
          ptr_(std::exchange(other.ptr_, nullptr)) {}

    // Move assignment operator
    MyClass &operator=(MyClass &&other) noexcept
    {
        if (this != &other)
        {
           
            value_ = std::exchange(other.value_, 0);
            ptr_ = std::exchange(other.ptr_, nullptr);
        }
        return *this;
    }

    int getValue() const { return value_; }
    int getPtrValue() const { return ptr_ ? *ptr_ : 0; }
};

int main()
{
    MyClass a(10, 100);
    MyClass b(20, 200);

    b = std::move(a); // Using move assignment

    std::cout << "a value after move: " << a.getValue() << std::endl;
    std::cout << "a ptr value after move: " << a.getPtrValue() << std::endl;
    std::cout << "b value after move: " << b.getValue() << std::endl;
    std::cout << "b ptr value after move: " << b.getPtrValue() << std::endl;

    return 0;
}

#include <memory>
#include <limits>
#include <vector>

using namespace std;
template <typename T>
class MyAllocator {
public:
    // Type definitions required by the Allocator concept
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;

    // Constructor and destructor (if needed)
    MyAllocator() noexcept {}
    MyAllocator(const MyAllocator&) noexcept {}
    template <typename U>
    MyAllocator(const MyAllocator<U>&) noexcept {}

    ~MyAllocator() noexcept {}

    // Allocate memory for 'n' objects of type T
    pointer allocate(size_type n, const void* hint = 0) {
        return static_cast<pointer>(::operator new(n * sizeof(T)));
    }

    // Deallocate memory pointed to by 'p'
    void deallocate(pointer p, size_type n) {
        ::operator delete(p);
    }

    // Optional methods: construct, destroy, max_size, etc.
    void construct(pointer p, const T& val) {
        new(static_cast<void*>(p)) T(val);
    }

    void destroy(pointer p) {
        p->~T();
    }

    size_type max_size() const noexcept {
        return std::numeric_limits<size_type>::max() / sizeof(T);
    }

    template <typename U>
    struct rebind {
        using other = MyAllocator<U>;
    };

    // Comparison operators (required)
    bool operator==(const MyAllocator&) const noexcept { return true; }
    bool operator!=(const MyAllocator&) const noexcept { return false; }
};

int main() {
    // Example usage with std::vector using MyAllocator
    std::vector<int, MyAllocator<int>> myVector;
    myVector.push_back(10);
    myVector.push_back(20);

    for (int value : myVector) {
        std::cout << value << std::endl;
    }

    return 0;
}

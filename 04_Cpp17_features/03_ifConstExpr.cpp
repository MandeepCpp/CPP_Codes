#include <iostream>
#include <type_traits>
#include <memory>

template <typename T>
auto get_value(T value) {
    if constexpr (std::is_pointer_v<T>) {
        return *value;
    } else if constexpr (std::is_same_v<std::decay_t<T>, std::shared_ptr<std::remove_pointer_t<T>>>> ||
                         std::is_same_v<std::decay_t<T>, std::unique_ptr<std::remove_pointer_t<T>>>>) {
        return *value;
    } else {
        return value;
    }
}

int main() {
    int a = 10;
    int* p = &a;
    std::shared_ptr<int> sp = std::make_shared<int>(20);
    std::unique_ptr<int> up = std::make_unique<int>(30);

    std::cout << "Value from int: " << get_value(a) << std::endl;         // Outputs 10
    std::cout << "Value from pointer: " << get_value(p) << std::endl;     // Outputs 10
    std::cout << "Value from shared_ptr: " << get_value(sp) << std::endl;  // Outputs 20
    std::cout << "Value from unique_ptr: " << get_value(up) << std::endl;  // Outputs 30

    return 0;
}

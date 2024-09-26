#include <iostream>
#include <optional>

std::optional<int> divide(int numerator, int denominator) {
    if (denominator == 0) {
        return std::nullopt; // Return an empty optional for division by zero
    }
    return numerator / denominator; // Return the result wrapped in std::optional
}

int main() {
    std::optional<int> result = divide(10, 2);
    if (result) {
        std::cout << *result; // Output: 5
    } else {
        std::cout << "Division by zero error"; // Handle the error case
    }

    return 0;
}

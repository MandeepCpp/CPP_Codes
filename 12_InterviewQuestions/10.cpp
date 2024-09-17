#include <iostream>

void countBinaryDigits(int num, int &count0, int &count1) {
    count0 = 0;
    count1 = 0;

    // while (num > 0) {
    //     if (num % 2 == 0) {
    //         count0++;
    //     } else {
    //         count1++;
    //     }
    //     num /= 2;
    // }

    while (num > 0) {
        if (num&1 == 1) {
            count1++;
        } else {
            count0++;
        }
        num >>=1;
    }
}

int main() {
    
    int count0 = 0, count1 = 0;
    countBinaryDigits(15, count0, count1);

    std::cout << "Number of 0s: " << count0 << std::endl;
    std::cout << "Number of 1s: " << count1 << std::endl;

    return 0;
}

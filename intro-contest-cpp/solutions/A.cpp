// Yandex Code Style
#include <iostream>

int main() {
    int number;
    int depth = 0;

    std::cin >> number;

    while (number / 2 + 1 >= 1 << depth) {
        ++depth;
    }

    int remainder = number - (1 << depth) + 2;
    int quantityToBuy = 0;
    
    if (remainder == 0) {
        quantityToBuy = 0;
    } else {
        quantityToBuy = (1 << depth) - remainder;
    }

    std::cout << depth - 1 << " " << quantityToBuy << std::endl;
    return 0;
}


// Yandex Code Style
#include <iostream>

int main() {
    int number;
    int previousNumber;
	int depth = 0;
    int currentPower = 2;

    std::cin >> number;
    
    previousNumber = number;
    number /= 2;
    ++number;

    while (number >= currentPower) {
        currentPower <<= 1;
        ++depth;
    }

    int remainder = previousNumber - 2 * ((1 << depth) - 1);
    int quantityToBuy = 0;
    
    if (remainder == 0) {
        quantityToBuy = 0;
    } else {
        quantityToBuy = (1 << (depth + 1)) - remainder;
    }

    std::cout << depth << " " << quantityToBuy << std::endl;
    return 0;
}


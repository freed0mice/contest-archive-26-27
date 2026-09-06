// Yandex Code Style
#include <iostream>
#include <vector>

int main() {
    size_t number = 0;
    unsigned long long leftHeight = 0;
    unsigned long long rightHeight = 0;
    std::vector<unsigned long long> array;

    std::cin >> number;
    
    array.resize(number);
    
    std::cin >> array[0];

    leftHeight = array[0];
    for (size_t i = 1; i < number; ++i) {
        std::cin >> array[i];
        rightHeight += array[i];
    }

    unsigned long long minHeight = 0;
    if (leftHeight > rightHeight) {
        minHeight = leftHeight;
    } else {
        minHeight = rightHeight;
    }

    unsigned long long currentMaxHeight = 0;
    for (size_t i = 1; i < number; ++i) {
        leftHeight += array[i];
        rightHeight -= array[i];

        if (leftHeight > rightHeight) { 
            currentMaxHeight = leftHeight;
        } else {
            currentMaxHeight = rightHeight;
        }

        if (minHeight > currentMaxHeight) {
            minHeight = currentMaxHeight;
        }
    }

    std::cout << minHeight << std::endl;
    return 0;
}

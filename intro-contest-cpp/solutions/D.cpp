// Yandex Code Style
#include <iostream>
#include <vector>
#include <cstdint>

const uint64_t MOD = 1000000007;

int main() {
    size_t number = 0;
    size_t k = 0;
    
    std::cin >> number >> k;

    if (number < k) {
        std::cout << 1 << std::endl;
        return 0;
    }
    
    std::vector<uint64_t> sequence(number + 1, 0);

    for (size_t i = 0; i < k; ++i) {
        sequence[i] = 1;
    }

    for (size_t i = k; i < number + 1; ++i) {
        for (size_t j = i - k; j < i; ++j) {
            sequence[i] += sequence[j];
        }
        sequence[i] %= MOD;
    }
    
    std::cout << sequence[number] << std::endl;
    return 0;
}

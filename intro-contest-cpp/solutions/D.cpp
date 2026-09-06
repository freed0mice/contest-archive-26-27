// Yandex Code Style
#include <iostream>
#include <vector>

const unsigned long long MOD = 1000000007;

int main() {
    size_t number = 0;
    size_t k = 0;
    std::vector<unsigned long long> sequence;
    
    std::cin >> number >> k;
    
    sequence.resize(number + 1);
    
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

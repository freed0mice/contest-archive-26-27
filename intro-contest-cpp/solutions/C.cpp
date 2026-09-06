// Yandex Code Style
#include <iostream>
#include <string>
#include <vector>
#include <utility>

int main() {
    int rows = 0;
    int cols = 0;

    std::cin >> rows >> cols;

    std::vector<std::string> grid(rows);
    for (int i = 0; i < rows; ++i) {
        std::cin >> grid[i];
    }

    std::vector<std::pair<int, int>> patternCells = {
        {0, 0}, {1, 0}, {2, 0}, {1, 1}, {0, 2}, {1, 2}, {2, 2}
    };
    std::vector<std::pair<int, int>> emptyCells = {
        {-1, -1}, {-1, 0}, {-1, 1}, {-1, 2}, {-1, 3},
        {0, -1}, {0, 1}, {0, 3},
        {1, -1}, {1, 3},
        {2, -1}, {2, 1}, {2, 3},
        {3, -1}, {3, 0}, {3, 1}, {3, 2}, {3, 3}
    };

    auto isValid = [rows, cols](int x, int y) {
        if (x < 0 || x >= rows) {
            return false;
        }
        
        if (y < 0 || y >= cols) {
            return false;
        }

        return true;
    };

    size_t count = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            bool stop = false;
            
            if (grid[i][j] == '#') {
                for (auto [pi, pj] : patternCells) {
                    if (!isValid(i + pi, j + pj) || grid[i + pi][j + pj] != '#') {
                        stop = true;
                        break;
                    }
                }

                if (stop) {
                    continue;
                }

                for (auto [ei, ej] : emptyCells) {
                    if (!isValid(i + ei, j + ej)) {
                        continue;
                    }

                    if (grid[i + ei][j + ej] != '.') {
                        stop = true;
                        break;
                    }
                }

                if (!stop) {
                    ++count;
                }
            }
        }
    }

    std::cout << count << std::endl;
    return 0;
}

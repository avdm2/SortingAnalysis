#include "../Headers/AlgoHeaders.h"

std::pair<int64_t, int64_t> shellSortShellSequence(std::vector<int>& data) {
    int64_t counter = 0;
    auto start = std::chrono::high_resolution_clock::now();

    counter += 3; // =, =, /
    size_t size = data.size();
    size_t gap = size / 2;
    while (gap > 0) {
        counter += 2; // >, =
        for (size_t i = gap; i < size; ++i) {
            counter += 4; // <, ++, =, =
            int temp = data[i];
            size_t j = i;
            while (j >= gap && data[j - gap] > temp) {
                counter += 6; // >=, -, >, =, -, -=
                data[j] = data[j - gap];
                j -= gap;
            }
            ++counter;
            data[j] = temp;
        }
        counter += 2;
        gap /= 2;
    }
    return {counter, getTime(start)};
}
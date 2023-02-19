#include "../Headers/AlgoHeaders.h"

std::pair<int64_t, int64_t> shellSortCiuraSequence(std::vector<int>& data) {
    int64_t counter = 0;
    auto start = std::chrono::high_resolution_clock::now();

    counter += 2; // =, =
    size_t size = data.size();
    size_t gap = 1;
    counter += 2; // <, /
    while (gap < size / 3) {
        counter += 3; // *, +, =
        gap = gap * 3 + 1;
    }

    ++counter;
    while (gap > 0) {
        counter += 2; // >, =
        for (size_t i = gap; i < size; ++i) {
            counter += 4; // <, ++, =, =
            int temp = data[i];
            size_t j;
            ++counter;
            for (j = i; j >= gap && data[j - gap] > temp; j-= gap) {
                counter += 6; // >=, -, >, -=, -, =
                data[j] = data[j - gap];
            }
            ++counter;
            data[j] = temp;
        }
        counter += 3; // -, /, =
        gap = (gap - 1) / 3;
    }
    return {counter, getTime(start)};
}
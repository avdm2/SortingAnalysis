#include "../Headers/AlgoHeaders.h"

std::pair<int64_t, int64_t> selectionSort(std::vector<int>& data) {
    int64_t counter = 0;
    auto start = std::chrono::high_resolution_clock::now();

    ++counter; // data.empty()
    if (data.empty()) {
        return {counter, getTime(start)};
    }

    counter += 2; // =, i = 0
    size_t size = data.size();
    for (size_t i = 0; i < size - 1; ++i) {
        counter += 6; // <, -, ++, =, +, =
        size_t min_index = i;
        for (size_t j = i + 1; j < size; ++j) {
            counter += 3; // <, ++, <
            if (data[j] < data[min_index]) {
                ++counter;
                min_index = j;
            }
        }
        ++counter;
        if (min_index != i) {
            ++counter;
            std::swap(data[i], data[min_index]);
        }
    }
    return {counter, getTime(start)};
}
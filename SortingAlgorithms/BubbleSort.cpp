#include "../Headers/AlgoHeaders.h"

std::pair<int64_t, int64_t> bubbleSort(std::vector<int>& data) {
    int64_t counter = 0;
    auto start = std::chrono::high_resolution_clock::now();

    ++counter; // data.empty()
    if (data.empty()) {
        return {counter, getTime(start)};
    }

    counter += 2; // size, i
    size_t size = data.size();
    for (size_t i = 0; i < size - 1; ++i) {
        counter += 4; // <, ++, j, -
        for (size_t j = 0; j < size - i - 1; ++j) {
            counter += 6; // <, ++, >, +, -, -
            if (data[j] > data[j + 1]) {
                counter += 2; // swap, j + 1
                std::swap(data[j], data[j + 1]);
            }
        }
    }
    return {counter, getTime(start)};
}

#include "../Headers/AlgoHeaders.h"

std::pair<int64_t, int64_t> bubbleSortIverson1(std::vector<int>& data) {
    int64_t counter = 0;
    auto start = std::chrono::high_resolution_clock::now();
    ++counter; // data.empty()
    if (data.empty()) {
        return {counter, getTime(start)};
    }

    counter += 2; // size, i = 0
    size_t size = data.size();
    bool swapped;
    for (size_t i = 0; i < size - 1; ++i) {
        counter += 5; // <, ++, =, j = 0, -
        swapped = false;
        for (size_t j = 0; j < size - i - 1; ++j) {
            counter += 6; // <, ++, >, +, -, -
            if (data[j] > data[j + 1]) {
                counter += 3; // swap, =, +
                std::swap(data[j], data[j + 1]);
                swapped = true;
            }
        }
        counter += 3; // true/false, <, -
        if (!swapped && i < size - 1) {
            break;
        }
    }
    return {counter, getTime(start)};
}
#include "../Headers/AlgoHeaders.h"

std::pair<int64_t, int64_t> bubbleSortIverson2(std::vector<int>& data) {
    int64_t counter = 0;
    auto start = std::chrono::high_resolution_clock::now();

    ++counter; // data.empty()
    if (data.empty()) {
        return {counter, getTime(start)};
    }

    counter += 3; // size, k, i
    size_t size = data.size();
    bool swapped;
    int k = 0;
    for (size_t i = 0; i < size - 1; ++i) {
        counter += 5; // <, ++, j = 0, =, -
        swapped = false;
        for (size_t j = 0; j < size - i - 1; ++j) {
            counter += 6; // <, ++, >, j + 1, -, -
            if (data[j] > data[j + 1]) {
                counter += 3; // swap, =, j + 1
                std::swap(data[j], data[j + 1]);
                swapped = true;
            }
        }
        ++counter; // true/false
        if (swapped) {
            ++counter; // =
            k = 0;
        } else {
            counter += 2; // ++, ==
            ++k;
            if (k == 2) {
                break;
            }
        }
    }
    return {counter, getTime(start)};
}
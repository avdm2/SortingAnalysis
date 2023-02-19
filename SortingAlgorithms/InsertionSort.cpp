#include "../Headers/AlgoHeaders.h"

std::pair<int64_t, int64_t> insertionSort(std::vector<int>& data) {
    int64_t counter = 0;
    auto start = std::chrono::high_resolution_clock::now();

    ++counter; // data.empty()
    if (data.empty()) {
        return {counter, getTime(start)};
    }

    counter += 2; // =, i = 1
    size_t size = data.size();
    for (int i = 1; i < size; ++i) {
        counter += 7; // <, ++, =, =, >=, >, -
        int key = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > key) {
            counter += 3; // j + 1, =, --
            data[j + 1] = data[j];
            --j;
        }
        counter += 2; // j + 1, =
        data[j + 1] = key;
    }
    return {counter, getTime(start)};
}

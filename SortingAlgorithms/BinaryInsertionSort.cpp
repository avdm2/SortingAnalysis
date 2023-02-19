#include "../Headers/AlgoHeaders.h"

std::pair<int64_t, int64_t> binaryInsertionSort(std::vector<int>& data) {
    int64_t counter = 0;
    auto start = std::chrono::high_resolution_clock::now();

    ++counter; // data.empty()
    if (data.empty()) {
        return {counter, getTime(start)};
    }

    counter += 2; // size, i
    size_t size = data.size();
    for (int i = 1; i < size; ++i) {
        counter += 3; // <, ++, =
        int key = data[i];
        ++counter; // pos
        int pos = std::lower_bound(data.begin(), data.begin() + i, key) - data.begin();
        counter += 2; // k, -
        for (int k = i - 1; k >= pos; --k) {
            counter += 4; // >=, --, =, +
            data[k + 1] = data[k];
        }
        ++counter;
        data[pos] = key;
    }
    return {counter, getTime(start)};
}
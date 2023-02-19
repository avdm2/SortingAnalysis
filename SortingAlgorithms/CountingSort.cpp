#include "../Headers/AlgoHeaders.h"

std::pair<int64_t, int64_t> countingSort(std::vector<int>& data) {
    int64_t counter = 0;
    auto start = std::chrono::high_resolution_clock::now();

    ++counter; // data.empty()
    if (data.empty()) {
        return {counter, getTime(start)};
    }

    ++counter; // =
    int max = *std::max_element(data.begin(), data.end());
    std::vector<int> count(max + 1, 0);
    for (const auto& value : data) {
        ++counter; // ++
        ++count[value];
    }
    counter += 2; // =, i = 0
    size_t index = 0;
    for (size_t i = 0; i < count.size(); ++i) {
        counter += 3; // <, ++, j = 0
        for (size_t j = 0; j < count[i]; ++j) {
            counter += 4; // <, ++, ++, =
            data[index++] = i;
        }
    }
    return {counter, getTime(start)};
}
#include "../Headers/AlgoHeaders.h"

void recursiveQuickSort(std::vector<int>& data, int left, int right, int64_t& counter) {
    counter += 5; // =, =, =, +, /
    int i = left, j = right, pivot = data[(left + right) / 2];
    while (i <= j) {
        ++counter;
        while (data[i] < pivot) {
            counter += 2; // <, ++
            i++;
        }
        while (data[j] > pivot) {
            counter += 2; // >, --
            j--;
        }
        ++counter;
        if (i <= j) {
            counter += 3; // swap, ++, ++
            std::swap(data[i] , data[j]);
            i++;
            j--;
        }
    }
    if (left < j) {
        recursiveQuickSort(data, left, j, counter);
    }
    if (i < right) {
        recursiveQuickSort(data, i, right, counter);
    }
}

std::pair<int64_t, int64_t> quickSort(std::vector<int>& data) {
    int64_t counter = 0;
    auto start = std::chrono::high_resolution_clock::now();
    recursiveQuickSort(data, 0, data.size() - 1, counter);
    return {counter, getTime(start)};
}
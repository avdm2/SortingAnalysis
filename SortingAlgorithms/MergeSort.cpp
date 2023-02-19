#include "../Headers/AlgoHeaders.h"

void merge(std::vector<int>& data, size_t left, size_t mid, size_t right, int64_t& counter) {
    counter += 7; // =, =, -, +, =, -, =
    size_t i = 0, j = 0, k;
    size_t n1 = mid - left + 1;
    size_t n2 = right - mid;

    std::vector<int> L(n1), R(n2);
    for (; i < n1; ++i) {
        counter += 4; // <, ++, +, =
        L[i] = data[left + i];
    }
    for (; j < n2; ++j) {
        counter += 5; // <, ++, +, +, =
        R[j] = data[mid + 1 + j];
    }

    counter += 3; // =, =, =
    i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        counter += 3; // <, <, <=
        if (L[i] <= R[j]) {
            counter += 2; // =, ++
            data[k] = L[i];
            ++i;
        } else {
            counter += 2; // =, ++
            data[k] = R[j];
            ++j;
        }
        ++counter;
        ++k;
    }

    while (i < n1) {
        counter += 4; // <, =, ++, ++
        data[k] = L[i];
        ++i;
        ++k;
    }
    while (j < n2) {
        counter += 4; // <, =, ++, ++
        data[k] = R[j];
        ++j;
        ++k;
    }
}

void recursiveMergeSort(std::vector<int>& data, size_t left, size_t right, int64_t& counter) {
    counter += 2; // >=, empty()
    if (left >= right || data.empty()) {
        return;
    }
    counter += 4; // +, -, /, =
    size_t mid = left + (right - left) / 2;
    recursiveMergeSort(data, left, mid, counter);
    recursiveMergeSort(data, mid + 1, right, counter);
    merge(data, left, mid, right, counter);
}

std::pair<int64_t, int64_t> mergeSort(std::vector<int>& data) {
    int64_t counter = 0;
    auto start = std::chrono::high_resolution_clock::now();
    recursiveMergeSort(data, 0, data.size() - 1, counter);
    return {counter, getTime(start)};
}
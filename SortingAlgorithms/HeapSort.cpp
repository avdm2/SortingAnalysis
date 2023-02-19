#include "../Headers/AlgoHeaders.h"

void buildHeap(std::vector<int>& data, int size, int i, int64_t& counter) {
    counter += 7; // *, +, =, *, +, =, =
    int left = 2 * i + 1, right = 2 * i + 2, max = i;
    counter += 2; // <, >
    if (left < size && data[left] > data[max]) {
        ++counter;
        max = left;
    }
    counter += 2; // <, >,
    if (right < size && data[right] > data[max]) {
        ++counter;
        max = right;
    }
    ++counter;
    if (max != i) {
        ++counter;
        std::swap(data[i], data[max]);
        buildHeap(data, size, max, counter);
    }
}

std::pair<int64_t, int64_t> heapSort(std::vector<int>& data) {
    int64_t counter = 0;
    auto start = std::chrono::high_resolution_clock::now();

    counter += 4; // size, /, -, =
    int size = data.size();
    for (int i = size / 2 - 1; i >= 0; --i) {
        counter += 2; // >=, --
        buildHeap(data, size, i, counter);
    }
    counter += 2; // =, -
    for (int i = size - 1; i >= 0; --i) {
        counter += 3; // >=, --, swap
        std::swap(data[0], data[i]);
        buildHeap(data, i, 0, counter);
    }
    return {counter, getTime(start)};
}
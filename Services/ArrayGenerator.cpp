#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

// Сделано две почти одинаковые функции заполнения вектора для удобства их использования в ArrayTypeEnum.h
std::vector<int> fill0To5(size_t size) {
    srand(time(nullptr));
    std::vector<int> result(size, 0);
    for (size_t i = 0; i < size; ++i) {
        result[i] = rand() % 5;
    }
    return result;
}

std::vector<int> fill0To4000(size_t size) {
    srand(time(nullptr));
    std::vector<int> result(size, 0);
    for (size_t i = 0; i < size; ++i) {
        result[i] = rand() % 4000;
    }
    return result;
}

std::vector<int> almostSorted(size_t size) {
    srand(time(nullptr));
    std::vector<int> result(size, 0);
    for (size_t i = 0; i < size; ++i) {
        result[i] = i + 1;
    }
    for (size_t i = 0; i < size / 2; ++i) {
        std::swap(result[rand() % size], result[rand() % size]);
    }
    return result;
}

std::vector<int> backwardSorted(size_t size) {
    srand(time(nullptr));
    std::vector<int> result(size, 0);
    int value = 4100;
    for (size_t i = 0; i < size; ++i) {
        result[i] = value;
        --value;
    }
    return result;
}
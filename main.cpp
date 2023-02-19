#include "Headers/SortingHeaders.h"

#include "Services/ArrayGenerator.cpp"
#include "Services/CSVWriter.cpp"

#include "Enums/ArrayTypeEnum.h"
#include "Enums/FunctionEnum.h"

void sortOneVector(std::vector<int>& data, const ArrayType& array_type) {
    for (int method = bin_ins; method != shell + 1; method++) {
        Sort type = static_cast<Sort>(method);
        int64_t avg_time = 0, ops = -1;
        for (int i = 0; i < 30; ++i) {
            auto [op, ns] = sortTypeToFunc(type)(data);
            avg_time += ns;
            ops = op;
        }
        writeCSV(arrayTypeToString(array_type), sortTypeToString(type), data.size(), avg_time / 30, ops);
    }
}

void testRange400To4100() {
    for (size_t size = 400; size <= 4100; size += 100) {
        for (int array_type = range0to5; array_type != backward + 1; array_type++) {
            auto type = static_cast<ArrayType>(array_type);
            std::vector<int> data = arrayTypeToFunc(type)(size);
            sortOneVector(data, type);
        }
    }
}

void testRange50To300() {
    for (size_t size = 50; size <= 300; size += 50) {
        for (int array_type = range0to5; array_type != backward + 1; array_type++) {
            auto type = static_cast<ArrayType>(array_type);
            std::vector<int> data = arrayTypeToFunc(type)(size);
            sortOneVector(data, type);
        }
    }
}

int main() {
    clearCSV();
    writeHeader();
    testRange50To300();
    testRange400To4100();
}





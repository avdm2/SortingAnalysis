#pragma once

#include <chrono>

int64_t getTime(std::chrono::high_resolution_clock::time_point start) {
    auto duration = std::chrono::duration_cast<std::chrono::high_resolution_clock::duration>(std::chrono::high_resolution_clock::now() - start);
    return duration.count();
}

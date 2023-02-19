#include <iostream>
#include <vector>
#include <fstream>

void writeVector(const std::string& path, const std::vector<int>& data, bool sorted, int64_t time, int64_t operations) {
    std::ofstream file(path, std::ios_base::app);
    if (data.empty()) {
        if (sorted) {
            return;
        }
        file << "DATA: EMPTY.\n\n";
        file.close();
        return;
    }
    if (sorted) {
        file << "SORTED. TIME = " << time << "ns; OPERATIONS = " << operations << ".\n";
    } else {
        file << "UNSORTED.\n";
    }
    file << "DATA = [";
    for (size_t i = 0; i < data.size(); ++i) {
        if (i != data.size() - 1) {
            file << data[i] << ", ";
        } else {
            file << data[i] << "].\n";
        }
    }
    if (sorted) {
        file << "\n";
    }
    file.close();
}
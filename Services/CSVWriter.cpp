#include <iostream>
#include <vector>
#include <fstream>

void writeHeader() {
    std::ofstream file("../Output/data.csv", std::ios_base::app);
    file << "Sort method;Array type;Amount;Time;Operations" << "\n";
    file.close();
}

void writeCSV(const std::string& type, const std::string& sort, const size_t& size, const int64_t& time, const int64_t& operations) {
    std::ofstream file("../Output/data.csv", std::ios_base::app);
    file << sort << ";" << type << ";" << size << ";" << time << ";" << operations << "\n";
    file.close();
}

void clearCSV() {
    std::ofstream file("../Output/data.csv", std::ios::out);
    file.close();
}
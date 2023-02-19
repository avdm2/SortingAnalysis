#include <functional>

enum ArrayType {
    range0to5,
    range0to4000,
    almost,
    backward
};

std::function<std::vector<int>(size_t&)> arrayTypeToFunc(ArrayType type) {
    switch (type) {
        case range0to5 : return fill0To5;
        case range0to4000 : return fill0To4000;
        case almost : return almostSorted;
        case backward : return backwardSorted;
        default : return nullptr;
    }
}

std::string arrayTypeToString(ArrayType type) {
    switch (type) {
        case range0to5 : return "fill0To5";
        case range0to4000 : return "fill0To4000";
        case almost : return "almostSorted";
        case backward : return "backwardSorted";
        default : return "default";
    }
}
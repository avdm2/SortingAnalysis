#include <functional>

enum Sort {
    bin_ins,
    bubble,
    iverson1,
    iverson2,
    counting,
    heap,
    insertion,
    merges,
    quick,
    selection,
    ciura,
    shell
};

std::function<std::pair<int64_t, int64_t>(std::vector<int>&)> sortTypeToFunc(Sort type) {
    switch (type) {
        case bin_ins : return binaryInsertionSort;
        case bubble : return bubbleSort;
        case iverson1 : return bubbleSortIverson1;
        case iverson2 : return bubbleSortIverson2;
        case counting : return countingSort;
        case heap : return heapSort;
        case insertion : return insertionSort;
        case merges : return mergeSort;
        case quick : return quickSort;
        case selection : return selectionSort;
        case ciura : return shellSortCiuraSequence;
        case shell : return shellSortShellSequence;
        default : return nullptr;
    }
}

std::string sortTypeToString(Sort type) {
    switch (type) {
        case bin_ins : return "binaryInsertionSort";
        case bubble : return "bubbleSort";
        case iverson1 : return "bubbleSortIverson1";
        case iverson2 : return "bubbleSortIverson2";
        case counting : return "countingSort";
        case heap : return "heapSort";
        case insertion : return "insertionSort";
        case merges : return "mergeSort";
        case quick : return "quickSort";
        case selection : return "selectionSort";
        case ciura : return "shellSortCiuraSequence";
        case shell : return "shellSortShellSequence";
        default : return "default";
    }
}
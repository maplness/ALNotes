#include <iostream>
#include "chapter2/mergeSort.h"
#include "utils/utils.h"

using namespace std;

int main() {
    int maxSize = 100;
    int maxValue = 100;
    vector<int> arr = generateRandomArray(maxSize, maxValue);
    printArr(arr);
    mergeSort(arr);
    printArr(arr);
}
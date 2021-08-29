#include <iostream>
#include "utils.h"
#include <stdlib.h>
#include <vector>

using namespace std;

void func1() {
    cout << "1" << endl;
    return;
}

vector<int> generateRandomArray(int maxSize, int maxValue) {
    int size = rand() % maxSize;
    vector<int> result;
    for (int i = 0; i < size; i++) {
        result.push_back(rand() % maxValue);
    }
    return result;
}

void printArr(vector<int> arr) {
    if (arr.empty()) {
        return;
    }
    for (int i = 0; i < arr.size(); i++ ) {
        cout << arr[i] << ",";
    }
    cout << endl;
}
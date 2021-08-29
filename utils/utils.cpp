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

void swap(vector<int> &arr, int i, int j) {
    arr[i] = arr[i] ^ arr[j];
    arr[j] = arr[i] ^ arr[j];
    arr[i] = arr[i] ^ arr[j];
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

ListNode* generateRandomLinkList(int maxSize, int maxValue) {
    int size = rand() % maxSize;
    int value = rand() % maxValue;
    ListNode *dummyHead = new ListNode(0);
    ListNode *node = new ListNode(value);
    dummyHead->next = node;
    for (int i = 0; i < size; i++)  {
        ListNode *tmp = new ListNode(rand() % maxValue);
        node->next = tmp;
        node = tmp;
    }
    return dummyHead->next;
}
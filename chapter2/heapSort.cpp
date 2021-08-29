#include "heapSort.h"
#include "../utils/utils.h"
#include <queue>

using namespace std;

void  heapInsert(vector<int> &arr, int index) {
    while( arr[index] > arr[(index - 1) / 2]) {
        swap(arr, index, (index-1) / 2);
        index = (index - 1)/2;
    }
}

void heapify(vector<int> &arr, int index, int size) {
    int left = index * 2 + 1;
    while(left < size) {
        int largest = left + 1 < size && arr[left + 1] > arr[left] ? left + 1 : left;
        largest = arr[largest] > arr[index] ? largest : index;
        if (largest == index) {
            break;
        } 
        swap(arr, largest, index);
        index = largest;
        left = index * 2 + 1;
    }
}

void heapSort(vector<int> &arr) {
    if (arr.empty() || arr.size() < 2) {
        return;
    }
    //构造大根堆
    for (int i = 0; i < arr.size(); i++) {
        heapInsert(arr, i);
    }
    //大根堆最大的在【0】位置， 每次swap0和最后位置， 一直swap到size为0， 此时即为有序数组
    int size = arr.size();
    swap(arr, 0 , --size);
    while (size > 0) {
        heapify(arr, 0 , size);
        swap(arr, 0 , --size);
    }
}

/**
 * 把一个size为k+1的堆当作滑动窗口
 * */
void sortArrayDistenceLessK(std::vector<int> &arr, int k) {
    priority_queue<int, vector<int>, greater<int>> smallHeap;
    int index = 0;
    int tmp = arr.size() < k ? arr.size() : k;
    for (; index < tmp; index++) {
        smallHeap.push(arr[index]);
    }
    int i = 0;
    for (; index < arr.size(); i++,index++) {
        smallHeap.push(arr[index]);
        arr[i] = smallHeap.top();
        smallHeap.pop();
    }
    while(!smallHeap.empty()) {
        arr[i++] = smallHeap.top();
        smallHeap.pop();
    }
}
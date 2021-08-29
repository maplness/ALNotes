#ifndef HEAPSORT_H_
#define HEAPSORT_H_

#include <vector>
void heapSort(std::vector<int> &arr);

/**
 * 已知一个几乎有序的数组， 几乎有序是指如果把数组排好序的话，每个元素移动的距离
 * 可以 不超过k， 并且k对于数组大小来说较小，请选择一个合适的排序算法对这个数组进行排序
 * */
void sortArrayDistenceLessK(std::vector<int> &arr, int k);



#endif
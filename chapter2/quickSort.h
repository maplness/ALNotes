#ifndef QUICKSORT_H_
#define QUICKSORT_H_

#include <vector>
/**
 *  荷兰国旗问题
 *  左中右
 *  NetherLandsFlag
 * */
void partition(std::vector<int> &arr, int l, int r, int p);

/** 快排 */
void quickSort(std::vector<int> &arr);


#endif
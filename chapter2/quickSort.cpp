#include "quickSort.h"
#include "../utils/utils.h"
#include <stdlib.h>

using namespace std;

void partition(vector<int> &arr, int l, int r , int p) {
    int less = l - 1;
    int more = r + 1;
    while (l < more) {
        if (arr[l] < p) {
            swap(arr, ++less, l++);
        } else if (arr[l] > p) {
            swap(arr, --more, l);
        } else {
            l++;
        }
    }
}

vector<int> partition(vector<int> &arr, int l, int r) {
    int less = l - 1;
    int more = r;
    while (l < more) {
        if (arr[l] < arr[r]) {
            swap(arr, ++less, l++);
        } else if (arr[l] > arr[r]) {
            swap(arr, --more, l);
        } else {
            l++;
        }
    }
    swap(arr, more, r);
    return {less + 1, more};
}

void quickSort(vector<int> &arr) {
    if (arr.empty() || arr.size() < 2) {
        return;
    }

}

void quickSort(vector<int> &arr, int l, int r) {
    if (l < r) {
        swap(arr, l + (int)(rand() % (r - l + 1)), r);
        vector<int> index = partition(arr, l, r);
        quickSort(arr, l, index[0] - 1);
        quickSort(arr, index[1] + 1, r);
    }
}
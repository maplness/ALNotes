#ifndef UTILS_H_
#define UTILS_H_

#include <vector>

/**
 * 链表节点定义
 * */
struct ListNode {
    int value;
    ListNode *next;
    ListNode(int value): value(value), next(nullptr) {}
};

struct DoubleNode {
    int value;
    DoubleNode *pre;
    DoubleNode *next;
    DoubleNode(int value): value(value), pre(nullptr), next(nullptr) {}
};

void func1();
//生成随机数组
std::vector<int> generateRandomArray(int maxSize, int maxValue);
//打印数组
void printArr(std::vector<int> arr);
//交换数组中i , j 位置
void swap(std::vector<int> &arr, int i, int j);
//生成随机链表
ListNode* generateRandomLinkList(int maxSize, int maxValue);
//打印单链表
void printList(ListNode *head);
//打印双向链表
void printDoubleList(DoubleNode *head);

#endif
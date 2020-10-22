# O22_148_sort_linklist

###### author:SCZ

![](https://tva1.sinaimg.cn/large/0081Kckwgy1gjy7ebaqwhj31gy0iawgh.jpg)

```objc
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        
        int length = getLength(head);
        ListNode *dummyHead = new ListNode(-1);
        dummyHead->next = head;

        ListNode *left , *right , *tail , *cur;
        for(int step = 1; step < length ; step <<= 1){
            cur = dummyHead->next;
            tail = dummyHead;
            while(cur){
                left = cur;
                right = splite(left, step);
                cur = splite(right , step);
                tail = merge(left , right , tail);
            }
        }
        return dummyHead->next;

    }
private:
    int getLength(ListNode *head){
        ListNode *cur = head;
        int count = 0;
        while(cur){
            cur = cur->next;
            count++;
        }
        return count;
    }
    ListNode* splite(ListNode *head , int length){
        
        for(int i = 1 ; head && i < length ; i++){
            head = head->next;
        }

        if(!head) return nullptr;
        ListNode *second = head->next;
        head->next = nullptr;
        return second;
    }

    ListNode* merge(ListNode *left, ListNode *right , ListNode *head){
        while(left && right){
            if(left->val <= right->val){
                head->next = left;
                left = left->next;
            }else {
                head->next = right;
                right = right->next;
            }
            head = head->next;
        }
        if(left!=nullptr) head->next = left;
        if(right!=nullptr) head->next = right;

        while(head->next) head = head->next; 

        return head;
    }
};
```

对于时间复杂度的要求，使用归并排序。如果使用归并排序form top to bottom 的策略 ， 空间复杂度做不到O(1).

所以采取from bottom to top 的策略，先两两归并，再四四归并，step*2。


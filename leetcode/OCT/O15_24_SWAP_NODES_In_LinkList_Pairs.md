# O15_24_SWAP_NODES_In_LinkList_Pairs

###### author:SCZ

![24](https://tva1.sinaimg.cn/large/007S8ZIlgy1gjqcl7wd09j311w0u0wkw.jpg)

```c++
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *fakeHead = new ListNode(0);
        fakeHead->next = head;
        ListNode *cur = fakeHead;
        while(cur->next!=nullptr && cur->next->next!=nullptr){
            ListNode *node1 = cur->next;
            ListNode *node2 = cur->next->next;
            cur->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            cur = node1;
        }
        return fakeHead->next;
    }
};
```



思路： 头节点不好搞可以搞一个fakehead
# O19_142_LinkList_Cycle

###### author:SCZ

![142](https://tva1.sinaimg.cn/large/007S8ZIlgy1gjuqig5rkrj30wi0u0qam.jpg)

```c++
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head , *slow = head;
        while(fast != nullptr){
            if(fast->next == nullptr){
                return nullptr;
            }
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                ListNode *pre = head;
                while(pre != slow){
                    pre = pre->next;
                    slow = slow->next;
                }
                return pre;
            }
        }
        return nullptr;
    }
};
```



判断链表是否有环， 快慢指针 ， 都从头出发，快指针走两步，慢指针走一步，链表有环的情况，当它们在环上相遇时，另外引入一个指针pre从头出发，与慢指针一样一次走一步，pre与慢指针相遇时，即为入环点。
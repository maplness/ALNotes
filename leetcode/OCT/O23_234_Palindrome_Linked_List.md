# O23_234_Palindrome_Linked_List

###### author : scz

![234](https://tva1.sinaimg.cn/large/0081Kckwgy1gjzc58mkc7j31hu0ky76i.jpg)

```c++
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode *fast = head , *slow = head , *pre = head;
        
        while(fast && fast->next){
            pre = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        pre->next = nullptr;
        ListNode *right = reverse(slow);
        while(head && right){
            if(head->val != right->val){
                return false;
            }
            head = head->next;
            right = right->next;
        }
        return true;
    }

private:
    ListNode* reverse(ListNode *head){
        if(!head || !head->next) return head;
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while(cur->next){
            ListNode *tmpPre = cur->next;
            //cur->next = pre, 然后cur右移，pre右移
            cur->next = pre;
            pre = cur;
            cur = tmpPre;
        }
        cur->next = pre;
        return cur;
    }
};
```



考虑O(n)时间复杂度和O(1)空间复杂度， 采用把链表从中间断开，然后翻转后半部分链表来做。

从中间断开使用快慢指针法，反转链表要熟练
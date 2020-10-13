<!--
 * @Author: your name
 * @Date: 2020-10-13 21:58:22
 * @LastEditTime: 2020-10-13 22:42:23
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \undefinedd:\Study\ALNotes\leetcode\OCT\O13_2_Add_Two_Numbers.md
-->
# O13_2_Add_Two_Numbers

###### author:LJW



![img-2918bc20d5fcdd98](https://i.bmp.ovh/imgs/2020/10/2918bc20d5fcdd98.png)

```C++
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr, *tail = nullptr;
        int carry = 0;
        while (l1 || l2) {
            int n1 = l1 ? l1->val: 0;
            int n2 = l2 ? l2->val: 0;
            int sum = n1 + n2 + carry;
            if (!head) {
                head = tail = new ListNode(sum % 10);
            } else {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            carry = sum / 10;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        if (carry > 0) {
            tail->next = new ListNode(carry);
        }
        return head;
    }
}
```

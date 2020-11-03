# Nov3_2_Sum_of_ListNode

* 迭代算法

```java
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int temp = l1.val + l2.val;
        int add = 0;
        ListNode addNode = null;
        if (temp >= 10) {
            temp = temp - 10;
            add++;
            addNode = new ListNode(add);
        }
        ListNode start = new ListNode(temp);
        ListNode result = start;
        result.next = addNode;

        ListNode next1 = l1.next;
        ListNode next2 = l2.next;
        while (next1 != null || next2 != null) {
            if (next1 != null || next2 != null) {
                result = getListNode(next1, next2, result);
            }
            next1 = next1==null?null:next1.next;
            next2 = next2==null?null:next2.next;
        }
        return start;
    }

    private ListNode getListNode(ListNode l1, ListNode l2, ListNode node) {
        ListNode next = node.next;
        int temp = (l1 == null ? 0 : l1.val) + (l2 == null ? 0 : l2.val) + (next == null?0:next.val);
        int add = 0;
        ListNode addNode = null;
        if (temp >= 10) {
            temp = temp - 10;
            add++;
            addNode = new ListNode(add);
        }
        ListNode result = new ListNode(temp);
        result.next = addNode;
        node.next = result;
        return result;
    }
}
```


# O19_23_merge_k_sorted_lists

###### author:scz

![23](https://tva1.sinaimg.cn/large/007S8ZIlgy1gjuxru3w0aj30xb0u0jwv.jpg)

```cpp
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (auto node: lists){
            if (node) {
                q.push({node->val,node});
            }
        }
        ListNode head, *tail = &head;
        while(!q.empty()){
            auto f = q.top();
            q.pop();
            tail->next = f.node;
            tail= tail->next;
            if(f.node->next){
                q.push({f.node->next->val, f.node->next});
            }
        }
        return head.next;
    }

private:
    struct tmp {
        int val;
        ListNode* node;
        bool operator < (const tmp &rhs) const{
            return val > rhs.val;
        }
    };
    priority_queue<tmp> q;
};
```

先把数组里的节点都放进一个小根堆，构造一个fake head , 然后在小根堆取top放在head后面

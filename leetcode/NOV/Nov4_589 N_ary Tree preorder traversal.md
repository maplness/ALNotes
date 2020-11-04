# Nov_4_589 NTree preorder traversal
![](https://tva1.sinaimg.cn/large/0081Kckwgy1gkdk8w96rhj30oa0o640j.jpg)

* 递归算法
``` C++

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        realPreorder(root , ans);
        return ans;
    }
private:
    void realPreorder(Node *root, vector<int>& ans){
        if(!root) return;
        ans.push_back(root->val);
        for( auto child : root->children){
            realPreorder(child, ans);
        }
    }
};
```

* 迭代算法

``` C++
class Solution {
public:
    vector<int> preorder(Node* root) {
        if(!root) return;
        vector<int> ans;
        stack<Node *> s;
        s.push(root);
        while(!s.empty()){
            auto node = s.top();
            s.pop();
            ans.push_back(node->val);
            for(auto it = node->children.rbegin() ; it!= node->children.rend() ; ++it){
                s.push(*it);
            }
        }
        return ans;
    }
};
```

关键是理解递归函数调用栈和用栈模拟递归函数调用栈
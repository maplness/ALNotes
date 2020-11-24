# Nov_24_429 N叉树层次遍历

``` c++
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if (!root) return result;
        queue<Node *> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            result.push_back(vector<int>());
            for(int i = 0 ; i < size ; i++){
                Node *node = q.front();
                for(int j = 0 ; j < node->children.size() ; j++){
                    q.push(node->children[j]);
                }
                result.back().push_back(node->val);
                q.pop();
            }
        }
        return result;
    }
};
```

使用队列层次遍历
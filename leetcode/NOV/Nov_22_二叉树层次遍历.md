# Nov_22_ 二叉树层次遍历

``` c++

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            result.push_back(vector<int> ());
            for(int i = 0;i<size;i++){
                TreeNode *node = q.front();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                result.back().push_back(node->val);
                q.pop();
            }
        }
        return result;
    }
};

```

用队列处理层次遍历，关键是用一个变量记录每一层的size
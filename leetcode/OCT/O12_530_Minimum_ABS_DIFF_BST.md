# O12_530_Minimum_ABS_DIFF_BST

###### author:SCZ

![image-20201012183059826](https://tva1.sinaimg.cn/large/007S8ZIlgy1gjmqbw0bifj31cu0tun0f.jpg)



```c++
class Solution {
public:

    void inorder(TreeNode *root , int& pre , int& ans){
        if(root == nullptr){
            return;
        }
        inorder(root->left, pre, ans);
        if(pre == -1){
            pre = root->val;
        }else{
            ans = min(ans, root->val - pre);
            pre = root->val;
        }
        inorder(root->right, pre, ans);
    }

    int getMinimumDifference(TreeNode* root) {
        int pre = -1 , ans = INT_MAX;
        inorder(root, pre , ans);
        return ans;
    }
};
```



将BST中序遍历， 用一个pre指针与当前节点的值做比较，更新ans值。
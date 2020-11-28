# Nov_28_669 修建二叉搜索树

``` C++
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root) return nullptr;
        if(root->val > high) return trimBST(root->left, low, high);
        if(root->val < low) return trimBST(root->right, low, high);

        root->left = trimBST(root->left, low , high);
        root->right = trimBST(root->right, low, high);

        return root;
    }
};
```

思路： 根据题目中是二叉搜索树，使用递归的思路 ， 认为trimBST(node)是理想子树， 如果node->val 大于 high ， 那么理想子树一定在该node左边， 反之一定在该node右边，如果不是，就在该node上修剪。
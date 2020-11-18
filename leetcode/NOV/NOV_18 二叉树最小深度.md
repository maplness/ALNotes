# NOV_18 二叉树最小深度
![](https://tva1.sinaimg.cn/large/0081Kckwgy1gktsk2qo2vj30u00zwq8i.jpg)

``` c++
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;

        int minLength = INT_MAX;
        if(root->left){
            minLength = min(minDepth(root->left) , minLength);
        }
        if(root->right){
            minLength = min(minDepth(root->right) , minLength);
        }

        return minLength + 1;
    }
};
```

都遍历一遍，递归求解
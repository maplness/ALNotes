# Nov_20_另一个树的子树

``` c++
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s){
            return false;
        }
        else if(isSameTree(s,t)){
            return true;
        }
        else {
            return isSubtree(s->left, t) || isSubtree(s->right, t);
        } 
    }

    bool isSameTree(TreeNode *p, TreeNode *q){
        if(!p && !q) return true;
        return   p && q && p->val == q->val && isSameTree(p->left,q->left) && isSameTree(p->right , q->right) ;
    }
};
```

枯燥递归
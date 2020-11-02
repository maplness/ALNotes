# N2_94_BinaryTree_Inorder_traversal

###### author:scz

![](https://tva1.sinaimg.cn/large/0081Kckwgy1gkaqga7yyqj31i80kktat.jpg)

* 递归算法

```c++
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root , result);
        return result;
    }
private:
    void traversal(TreeNode *root, vector<int> &result){
        if(!root){
            return;
        }
        traversal(root->left,result);
        result.push_back(root->val);
        traversal(root->right,result);
    }
};
```

* 迭代算法

```c++
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
				vector<int> res;
      	stack<TreeNode *> stack;
      	while(root != nullptr || !stack.empty()){
					while(root != nullptr){
            stack.push(root);
            root = root->left;
          }//end while
          root = stack.top();
          stack.pop();
          res.push_back(root->val);
          root = root->right;
        }//end while
      	return res;
    }
};
```

* morris算法（空间复杂度O(1) ）

就是简化了迭代算法中的弹栈，需要弹栈的时候直接通过维护的右子树找到对应节点。

```c++
class Solution {
  public:
  	vector<int> inorderTraversal(TreeNode *root){
      vector<int> res;
      TreeNode *predecessor = nullptr;
      
      while(root != nullptr){
        if(root->left != nullptr){
          // predecessor节点就是中序遍历前一个节点，向左走一步然后一直向右走
          predecessor = root->left;
          while(predecessor->right != nullptr && predecessor->right != root){
            predecessor = predecessor->right;
          }
          
          //让predecessor的右指针指向root , 继续遍历左子树
          if (predecessor->right == nullptr){
            predecessor->right = root;
            root = root->left;
          }
          //说明左子树已经访问完了，我们需要断开链接
          else {
            res.push_back(root->val);
            predecessor->right = nullptr;
            root = root->right;
          }
        }
        //如果没有左孩子，则直接访问右孩子
        else{
          res.push_back(root->val);
          root = root->right;
        }
      }
      return res;
    }
}
```


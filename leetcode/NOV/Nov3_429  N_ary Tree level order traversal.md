# Nov3_429  N_ary Tree level order traversal

![](https://tva1.sinaimg.cn/large/0081Kckwgy1gkc9434nrfj31dw0u0tbv.jpg)

* 递归算法

```c++
class Solution{
  public: 
  	vector<vector<int>> levelOrder(Node *root){
			vector<vector<int>> ans;
      levelOrder(root , 0 , ans);
      return ans;
    }
  private:
  	void levelOrder(Node *root, int d , vector<vector<int>>& ans){
      if (root == nullptr) return;
      while (ans.size() <= d) ans.push_back({});
      ans[d].push_back(root->val);
      for(auto child : root->children){
        levelOrder(child , d+1 , ans);
      }
    }
}
```

* 迭代算法

```c++
class Solution {
  public:
  	vector<vector<int>> levelOrder(Node *root){
      if(!root) return {};
      vector<vector<int>> ans;
      queue<Node*> q;
      q.push(root);
      int depth = 0;
      while (!q.empty()) {
        int size = q.size();
        ans.push_back({});
        while(size--){
          Node *n = q.front();
          q.pop();
          ans[depth].push_back(n->val);
          for(auto child : n->children){
            q.push(child);
          }
        }
        ++ depth;
      }
      return ans;
    }
};
```


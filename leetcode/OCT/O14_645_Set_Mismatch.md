# O14_645_Set_Mismatch

###### author: scz

![leetcode 645](https://tva1.sinaimg.cn/large/007S8ZIlgy1gjoweblkrkj31wq0metct.jpg)



根据样本的特点优化算法。

**思路：** 	（键值反转）样本特点是自然数，只有一个重复值。查找重复值用index位上的值作为index去遍历数组，遍历标识设计为乘-1.当以重复的index访问数组时，该位置上已经为负。数组都遍历一次后，只有一个正数，这个正数所在的index就是缺失的值。



```c++
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int repeat = -1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[abs(nums[i]) - 1] < 0){
                repeat = abs(nums[i]);
            }else{
                nums[abs(nums[i]) - 1] *= -1;
            }
        }
        
        int empty = -1;
        for(int i = 0 ; i < nums.size(); i++){
            if(nums[i] > 0){
                empty = i + 1;
                break;
            }
        }
        
        return {repeat , empty};
    }
};
```


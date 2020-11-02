# Nov2_349_Overlap_In_Array

###### author:jerry

* 递归算法

```c++
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        List<Integer> numList1 = toDistinctArrayList(nums1);
        List<Integer> numList2 = toDistinctArrayList(nums2);
        int length = numList1.size();
        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < numList1.size(); i++) {
            Integer nextNum = getNextNum(numList1.get(i), numList2);
            if (nextNum != null) {
                result.add(nextNum.intValue());
            }
        }
        int a[] = new int[result.size()];
        for (int i = 0; i < result.size(); i++) {
            a[i] = result.get(i);
        }
        return a;
    }

    private Integer getNextNum(Integer integer, List<Integer> numList2) {
        if (numList2.contains(integer)) {
            return integer;
        }
        return null;
    }


    private List<Integer> toDistinctArrayList(int[] nums) {
        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            if (!result.contains(nums[i])) {
                result.add(nums[i]);
            }
        }
        return result;
    }
```

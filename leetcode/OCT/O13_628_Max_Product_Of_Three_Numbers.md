# O13_628_Max_Product_Of_Three_Numbers

###### author:SCZ



![image-20201013151838143](https://tva1.sinaimg.cn/large/007S8ZIlgy1gjnqcuqy3ij31sp0u042t.jpg)



解法1:

 traverse 1 time ,  find 1st , 2nd minimum and 1st , 2 nd, 3th maximum number.

`int min1, min2 , max1, max2 , max3 ;`

the biggest product is `max(max1*max2*max3, min1*min2*min3)`

To prove , consider all kinds of situations.

Time complexity : O(n);(traverse for 1 time)

space complexity: O(1); (five virable)



```C++
int maximumProduct2(vector<int>& nums) {
		int min1 = INT_MAX, min2 = INT_MAX , max1 = INT_MIN , max2 = INT_MIN , max3 = INT_MIN;
		for (int i = 0;i < nums.size(); i++ ) {
			if (nums[i] < min1) {
				min2 = min1;
				min1 = nums[i];
			}else if (nums[i] < min2) {
				min2 = nums[i];
			}
			if (nums[i] > max1) {
				max3 = max2;
				max2 = max1;
				max1 = nums[i];
			}else if(nums[i] > max2){
				max3 = max2;
				max2 = nums[i];
			}else if(nums[i] > max3){
				max3 = nums[i];
			}
		}
		
		return max(max1*max2*max3, min1*min2*max1);
	}

```

解法2:

DP:



定义二维数组`f[2][4]`

`f[0][j] 表示j个数字所能构成乘积的最大值`

`f[1][j] 表示j个数字所能构成乘积的最小值`

`题解即为f[0][3]`

初始化如下。

|  1   | INT_MIN | INT_MIN | INT_MIN |
| :--: | :-----: | :-----: | :-----: |
|  1   | INT_MAX | INT_MAX | INT_MAX |

`f[0][j] = max(f[0][j], max(f[0][j-1] * nums[i] , f[1][j-1] * nums[i]))`

`f[1][j] = min(f[1][j] , min(f[0][j-1] * nums[i] , f[1][j-1] * nums[i]))`



```c++
int maximumProduct(vector<int>& nums) {
		int f[2][4], i, j;
		f[0][0] = f[1][0] = 1;
		for (j = 3; j > 0; --j) {
			f[0][j] = INT_MIN;
			f[1][j] = INT_MAX;
		}        
		
		for (i = 0; i < nums.size(); ++i) {
			for (j = 3; j > 0; --j) {
				if (f[0][j - 1] == INT_MIN) {
					continue;
				}
				f[0][j] = max(f[0][j], max(f[0][j - 1] * nums[i], f[1][j - 1] * nums[i]));
				f[1][j] = min(f[1][j], min(f[0][j - 1] * nums[i], f[1][j - 1] * nums[i]));
			}
		}                              
		return f[0][3];
	}
```


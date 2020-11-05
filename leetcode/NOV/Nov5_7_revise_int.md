# Nov5_7_revise_int

* 思路
利用TDD的方式，细化问题，逐个解决
要考虑的点：  
-负数  
-0结尾的正负数  
-极限的最大值  
-极限的最小值  
-反转之后会超过极限值   


```java
package com.joker.reverseInt;

public class ReviseInt {
    public int reverse(int x) {
        boolean negative = false;
        if (x < 0) {
            negative = true;
            if (x == -x) {
                return 0;
            }
            x = -x;
        }
        int result = x % 10;
        x = x / 10;
        while (x > 0) {
            if (result != 0 && ((!negative && Integer.MAX_VALUE / result < 10)
                    || (negative && Integer.MIN_VALUE/result > -10))) {
                return 0;
            }
            result = result * 10 + x % 10;
            x = x / 10;
        }
        if (negative) {
            return -result;
        }
        return result;
    }
}

```


# Nov6_8_huiwen

* 思路  
1. 转置整个数字，对比两个值
2. 转成string，首尾对比
3. 数字截取，中间值对比 


```java
public class Huiwen {
    public boolean isPalindrome(int x) {
        return method2(x);
    }

    private boolean method2(int x) {
        if (x < 0) {
            return false;
        }
        if (x < 10) {
            return true;
        }
        int length = getIntLength(x);
        int mid = length / 2;
        int another = 0;
        for (int i = 0; i < mid; i++) {
            another = another * 10 + x % 10;
            x = x / 10;
        }
        if (length % 2 == 1) {
            x = x / 10;
        }
        return x == another;
    }

    private int getIntLength(int x) {
        if (x < 100000) {
            if (x < 100) {
                if (x < 10) {
                    return 1;
                }
                return 2;
            } else if (x < 10000) {
                if (x < 1000) {
                    return 3;
                }
                return 4;
            }
            return 5;
        } else {
            if (x < 10000000) {
                if (x < 1000000) {
                    return 6;
                }
                return 7;
            } else if (x < 1000000000) {
                if (x < 100000000) {
                    return 8;
                }
                return 9;
            }
            return 10;
        }
    }

    private boolean method1(int x) {
        if (x < 0) {
            return false;
        }
        String key = String.valueOf(x);
        if (key.length() == 1) {
            return true;
        }
        int length = key.length() / 2;

        for (int i = 0; i <= length; i++) {
            int end = key.length();
            if (end == 1) {
                return true;
            }
            if (!key.substring(0, 1).equals(key.substring(end - 1))) {
                return false;
            }
            key = key.substring(1);
            if (key.length() == 1) {
                return true;
            }
            key = key.substring(0, key.length() - 1);
        }
        return true;
    }
}

```


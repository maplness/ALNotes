# Nov4_3_Max_Length_of_SubStr

* 迭代算法

```java
public class LongestStr {
    private int length = 0;
    private String base;

    public int lengthOfLongestSubstring(String s) {
        if(s.length()<2){
            return s.length();
        }
        base = s.substring(0,1);
        s = s.substring(1,s.length());

        while (s.length()>0){
            s = updateBaseStr(s);
        }
        return length;
    }

    private String updateBaseStr(String s) {
        if(s.length()!=0){
            String temp = s.substring(0,1);
            if(!base.equals(temp)&&!base.contains(temp)){
                base += temp;
                if(base.length()>length){
                    length = base.length();
                }
            }else if(base.length()>1 && base.contains(temp)){
                String[] strings = base.split(temp);
                if(strings.length>1){
                    base = strings[1] + temp;
                }else {
                    base = temp;
                }
            }else{
                if(base.length()>length){
                    length = base.length();
                }
                base = temp;
            }

            s = s.substring(1,s.length());
        }
        return s;
    }
}
```


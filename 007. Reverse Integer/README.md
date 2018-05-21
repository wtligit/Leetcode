# 7. Reverse Integer

标签（空格分隔）： Leetcode

---

>Given a 32-bit signed integer, reverse digits of an integer.

**Example 1:**
Input: `123`
Output: `321`

**Example 2:**

Input: `-123`
Output: `-321`
**Example 3:**
Input: `120`
Output: `21`

这个题注意判断溢出就可以了
```
class Solution {
    //反复将个位数字前移
public:
    int reverse(int x) {
        const int max = 0x7fffffff;  //int最大值  
        const int min = 0x80000000;  //int最小值 
        long long sum=0;
        while(x!=0){
            int tmp=x%10;
            sum=sum*10+tmp;
            //关键在于判断溢出
            if(sum>max||sum<min){
                return 0;
            }
            x/=10;
        }
        return sum;
    }
};
```





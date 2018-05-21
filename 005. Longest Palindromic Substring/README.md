# 5. Longest Palindromic Substring

标签（空格分隔）： Leetcode

---
>Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

**Example 1:**
Input: `"babad"`
Output: `"bab"`
Note: `"aba"` is also a valid answer.

**Example 2:**
Input: `"cbbd"`
Output: `"bb"`

解法一：利用动态规划
我们定义一个二维数组dp，其中dp[i][j]表示字符串区间[i, j]是否为回文串，是的话记值为1，否则为0；
状态转移方程为：dp[i][j]=1  if i==j（i和j指向同一个字符，当然是回文串）
dp[i][j]= s[i]==s[j]   if j==i+1（当i和j相邻的时候，对应字符相等，为回文串）
dp[i][j]=(s[i]==s[j]&&dp[i+1][j-1])  if i-j>2（当i和j不相邻的时候，还要保证内部的子串为回文串）
```
class Solution {
public:
    string longestPalindrome(string s) {
        int dp[s.size()][s.size()]={0};
        int left=0,right=0;
        int len=0;
        for(int i=0;i<s.size();i++){
            for(int j=0;j<i;j++){
                dp[j][i]=(s[i]==s[j]&&(i-j<2||dp[j+1][i-1]));
                if(dp[j][i]&&len<i-j+1){
                    len=i-j+1;
                    left=j;
                    right=i;
                }
            }
            dp[i][i]=1;
        }
        return s.substr(left,right-left+1);
    }
};
```

解法二：马拉车算法
详情参考：http://www.cnblogs.com/grandyang/p/4475985.html
```
class Solution {
public:
        string t ="$#";
        for (int i = 0; i < s.size(); ++i) {
            t += s[i];
            t += '#';
        }
        int p[t.size()] = {0}, id = 0, mx = 0, resId = 0, resMx = 0;
        for (int i = 0; i < t.size(); ++i) {
            p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
            while (t[i + p[i]] == t[i - p[i]]) ++p[i];
            if (mx < i + p[i]) {
                mx = i + p[i];
                id = i;
            }
            if (resMx < p[i]) {
                resMx = p[i];
                resId = i;
            }
        }
        return s.substr((resId - resMx) / 2, resMx - 1);
    }
};
```






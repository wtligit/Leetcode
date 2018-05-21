# 3. Longest Substring Without Repeating Characters

标签（空格分隔）： Leetcode

---

>Given a string, find the length of the **longest substring** without repeating characters.

**Examples:**
Given `"abcabcbb"`, the answer is `"abc"`, which the length is 3.
Given `"bbbbb"`, the answer is `"b"`, with the length of 1.
Given `"pwwkew"`, the answer is `"wke"`, with the length of 3. Note that the answer must be a **substring**, `"pwke"` is a subsequence and not a substring.

这个题是求一个字符串中最长的不存在重复字符的子串的长度。
子串的题目的常用做法是双指针，具体做法见注释。
```
class Solution {
    //这个题有点意思，要注意一下
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256,-1);
        int res=0;
        //start表示子串的左边，i表示子串的右边
        int start=-1;
        for(int i=0;i<s.size();i++){
            if(start<dict[s[i]]){
                //这个if实际上是在处理重复字符，如果后面遇到前面出现过的字符的话，dict是会比start大的，这个时候把start放在这个位置上，因为上一个无重读的子串已经统计完了，start放在新的位置上，开始一次新的统计
                start=dict[s[i]];
            }
            //每次更新这个字符所在的位置
            dict[s[i]]=i;
            res=max(res,i-start);
        }
        return res;
    }
};
```





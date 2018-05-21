# 6. ZigZag Conversion

标签（空格分隔）： Leetcode

---

>The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P  &nbsp;&nbsp; A &nbsp;&nbsp;&nbsp;&nbsp;  H &nbsp;&nbsp;&nbsp;&nbsp;  N
&nbsp;A &nbsp;P&nbsp; L &nbsp;S &nbsp;I &nbsp;I&nbsp; G
&nbsp;&nbsp;Y  &nbsp;&nbsp;&nbsp;&nbsp; I  &nbsp;&nbsp;&nbsp;&nbsp; R
And then read line by line: `"PAHNAPLSIIGYIR"`

Write the code that will take a string and make this conversion given a number of rows:

`string convert(string s, int numRows);`
**Example 1:**
Input: s = `"PAYPALISHIRING"`, numRows = 3
Output: `"PAHNAPLSIIGYIR"`
**Example 2:**
Input: s = `"PAYPALISHIRING"`, numRows = 4
Output: `"PINALSIGYAHRPI"`


这道题的关键在于按层来存储字符，然后把这些字符按层加在一个空字符串后面。对层的控制由step来实现。
```
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<=1){
            return s;
        }
        int len=s.length();
        string *tmp=new string[numRows];
        int row=0,step=1;
        for(int i=0;i<len;i++){
            tmp[row].push_back(s[i]);
            if(row==0){
                step=1;
            }else if(row==numRows-1){
                step=-1;
            }
            row+=step;
        }
        string res;
        for(int i=0;i<numRows;i++){
            res.append(tmp[i]);
        }
        delete[] tmp;
        return res;
    }
};
```





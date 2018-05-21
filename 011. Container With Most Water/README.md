# 11. Container With Most Water

标签（空格分隔）： Leetcode

---

>Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

>给一个数组，其中数组在下标i处的值为A[i]，坐标(i,A[i])和坐标(i,0)构成一条垂直于坐标轴x的直线。现任取两条垂线和x轴组成四边形容器。问其中盛水量最大为多少？

双指针暴力求解即可
```
class Solution {
    //双指针
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int res=0;
        while(left<right){
            res=max(res,(right-left)*min(height[left],height[right]));
            if(height[left]<height[right]){
                left++;
            }else{
                right--;
            }
        }
        return res;
    }
};
```





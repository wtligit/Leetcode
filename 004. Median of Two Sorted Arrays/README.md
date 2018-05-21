# 4. Median of Two Sorted Arrays

标签（空格分隔）： Leetcode

---

>There are two sorted arrays **nums1** and **nums2** of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be `O(log (m+n))`.

**Example 1:**
nums1 = `[1, 3]`
nums2 = `[2]`
The median is `2`

**Example 2:**
nums1 = `[1, 2]`
nums2 = `[3, 4]`
The median is `(2 + 3)/2 = 2.5`

解法一：最简单的解法，把num1和nums2按顺序存入一个新的数组num，然后返回num中最中间的那个数即可。时间复杂读是o(m+n)，不过也是A了。
```
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1=nums1.size();
        int len2=nums2.size();
        vector<int> num;
        int flag=1;
        if(len1==0&&len2==0){
            return 0;
        }
        if(len1==0){
            for(int j=0;j<len2;j++){
                num.push_back(nums2[j]);
            }
            flag=0;
        }
        if(len2==0){
            for(int i=0;i<len1;i++){
                num.push_back(nums1[i]);
            }
            flag=0;
        }
        if(flag){
            for(int i=0,j=0;i<len1||j<len2;){
                if(nums1[i]<nums2[j]){
                    num.push_back(nums1[i]);
                    i++;
                    if(i==len1||i>len1){
                        while(j<len2){
                            num.push_back(nums2[j++]);
                        }
                        break;
                    }
                }else{
                    num.push_back(nums2[j]);
                    j++;
                    if(j==len2){
                        while(i<len1){
                            num.push_back(nums1[i++]);
                        }
                        break;
                    }
                }
            }
        }
        if((len1+len2)%2){
            return num[(len1+len2)/2];
        }else{
            return double((num[(len1+len2)/2]+num[(len1+len2)/2-1]))/2;
        }
    }
};
```





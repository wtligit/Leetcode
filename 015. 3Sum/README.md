# 15. 3Sum

标签（空格分隔）： Leetcode

---
>Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

**Note:**
The solution set must not contain duplicate triplets.

**Example:**
Given array nums = `[-1, 0, 1, 2, -1, -4],`
A solution set is:
[
  `[-1, 0, 1],`
  `[-1, -1, 2]`
]


这个题思想上还是挺巧妙的。核心思想就是固定一个数，然后调整另外两个数。需要注意的是先对所有数字进行排序，这样就可以用while循环来略过重复的数。
```
class Solution {
    //双指针，固定第一个数，然后调整另外两个数，需要注意的是先对所有数字进行排序
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            while(i>0&&i<nums.size()&&nums[i]==nums[i-1]){
                i++;
            }
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                if(nums[i]+nums[j]+nums[k]==0){
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[j]);
                    tmp.push_back(nums[k]);
                    res.push_back(tmp);
                    tmp.clear();
                    j++;
                    k--;
                    while(j<k&&nums[j]==nums[j-1]){
                        j++;
                    }
                    while(k>j&&nums[k]==nums[k+1]){
                        k--;
                    }
                }
                if(nums[i]+nums[j]+nums[k]<0){
                    j++;
                    while(j<k&&nums[j]==nums[j-1]){
                        j++;
                    }
                }
                if(nums[i]+nums[j]+nums[k]>0){
                    k--;
                    while(k>j&&nums[k]==nums[k+1]){
                        k--;
                    }
                }
            }
        }
        return res;
    }
};
```





# 1. Two Sum

标签（空格分隔）： Leetcode

---

>Given an array of integers, return **indices** of the two numbers such that they add up to a specific target.
You may assume that each input would have **exactly** one solution, and you may not use the same element twice.

**example:**
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

这道题很简单，就是在一个数组中，找到和为target的两个数，且只有一个数字对满足条件。
最直观的做法就是遍历两遍数组，找到这两个数。这里需要注意的是第二次循环的`j=i+1`，这样可以避免重复遍历。
```
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }
    }
};
```

第二种做法是利用hash的思想，用`unordered_map`和`count`来实现。
unordered_map和map类似，都是存储的key-value的值，可以通过key快速索引到value。不同的是unordered_map不会根据key的大小进行排序
如果需要内部元素自动排序，使用map，不需要排序使用unordered_map
map中count()的结果只能为0和1，count()方法返回值是一个整数，1表示有这个元素，0表示没有这个元素。
```
class Solution {  
public:  
    vector<int> twoSum(vector<int>& nums, int target) {  
        vector<int> res;  
        int len = nums.size();  
        unordered_map<int,int> m;  
        for (int i = 0; i < len; i++){  
            if (m.count(target - nums[i])){  
                res.push_back(i);  
                res.push_back(m[target - nums[i]]);  
                return res;  
            }  
            m[nums[i]] = i;  
        }  
        return res;  
    }  
};
```




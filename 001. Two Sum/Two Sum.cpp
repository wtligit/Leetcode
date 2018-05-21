//可能有负数
/*
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
*/
/*
unordered_map和map类似，都是存储的key-value的值，可以通过key快速索引到value。不同的是unordered_map不会根据key的大小进行排序
如果需要内部元素自动排序，使用map，不需要排序使用unordered_map
map中count()的结果只能为0和1，count()方法返回值是一个整数，1表示有这个元素，0表示没有这个元素。
*/
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
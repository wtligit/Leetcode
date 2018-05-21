class Solution {
    //双指针
    //https://segmentfault.com/a/1190000008824222
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
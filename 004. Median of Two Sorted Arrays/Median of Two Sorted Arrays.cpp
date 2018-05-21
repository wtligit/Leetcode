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
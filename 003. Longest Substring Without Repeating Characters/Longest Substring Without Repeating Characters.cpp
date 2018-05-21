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
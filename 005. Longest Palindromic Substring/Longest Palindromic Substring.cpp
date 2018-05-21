class Solution {
    //http://www.cnblogs.com/grandyang/p/4464476.html
public:
    string longestPalindrome(string s) {
        int dp[s.size()][s.size()]={0};
        int left=0,right=0;
        int len=0;
        for(int i=0;i<s.size();i++){
            for(int j=0;j<i;j++){
                dp[j][i]=(s[i]==s[j]&&(i-j<2||dp[j+1][i-1]));
                if(dp[j][i]&&len<i-j+1){
                    len=i-j+1;
                    left=j;
                    right=i;
                }
            }
            dp[i][i]=1;
        }
        return s.substr(left,right-left+1);
        /*
        马拉车算法http://www.cnblogs.com/grandyang/p/4475985.html
        string t ="$#";
        for (int i = 0; i < s.size(); ++i) {
            t += s[i];
            t += '#';
        }
        int p[t.size()] = {0}, id = 0, mx = 0, resId = 0, resMx = 0;
        for (int i = 0; i < t.size(); ++i) {
            p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
            while (t[i + p[i]] == t[i - p[i]]) ++p[i];
            if (mx < i + p[i]) {
                mx = i + p[i];
                id = i;
            }
            if (resMx < p[i]) {
                resMx = p[i];
                resId = i;
            }
        }
        return s.substr((resId - resMx) / 2, resMx - 1);
        */
    }
};
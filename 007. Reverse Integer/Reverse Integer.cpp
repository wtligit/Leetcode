class Solution {
    //https://www.2cto.com/kf/201503/383937.html
    //反复将个位数字前移
public:
    int reverse(int x) {
        const int max = 0x7fffffff;  //int最大值  
        const int min = 0x80000000;  //int最小值 
        long long sum=0;
        while(x!=0){
            int tmp=x%10;
            sum=sum*10+tmp;
            //关键在于判断溢出
            if(sum>max||sum<min){
                return 0;
            }
            x/=10;
        }
        return sum;
    }
};
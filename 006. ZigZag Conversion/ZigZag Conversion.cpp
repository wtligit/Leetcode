class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<=1){
            return s;
        }
        int len=s.length();
        string *tmp=new string[numRows];
        int row=0,step=1;
        for(int i=0;i<len;i++){
            tmp[row].push_back(s[i]);
            if(row==0){
                step=1;
            }else if(row==numRows-1){
                step=-1;
            }
            row+=step;
        }
        string res;
        for(int i=0;i<numRows;i++){
            res.append(tmp[i]);
        }
        delete[] tmp;
        return res;
    }
};
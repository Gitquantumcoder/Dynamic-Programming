class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>9*num) return "";
        string ans(num,'9');
        int diff=9*num-sum;
        for(int i=num-1;i>=0;i--){
            if(diff==0) break;
            if(diff<=9 && ans[i]!=0){
                int digit=9-diff;
                ans[i]=digit+'0';
                diff=0;
            }
            if(diff>9){
                ans[i]='0';
                diff-=9;
            }
        }
        return diff==0?ans:"";
    }
};
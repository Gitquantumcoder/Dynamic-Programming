class Solution {
public:
    bool checkPowersOfThree(int n) {
        int cap=0;
        int temp=1;
        while(temp<n){
            temp=pow(3,cap);
            if(pow(3,(cap+1))>n){
                break;
            }
            cap++;
        }
        for(int i=cap;i>=0;i--){
            int power=pow(3,i);
            if(power<=n){
                n-=power;
            }
        }
        return n==0;
    }
};
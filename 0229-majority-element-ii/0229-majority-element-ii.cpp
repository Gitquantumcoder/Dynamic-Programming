class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size(),c1=0,c2=0,count1=0,count2=0;
        for(int it:nums){
            if(it==c1 && count1>0) count1++;
            else if(it==c2 && count2>0) count2++;
            else if(count1==0){
                c1=it;
                count1=1;
            }
            else if(count2==0){
                c2=it;
                count2=1;
            
            }
            else{
                count1--;
                count2--;
            }
        }
        count1=0;
        count2=0;
        for(int it:nums){
            if(it==c1) count1++;
            else if(it==c2)count2++;
        }
        if(count1>n/3) ans.push_back(c1);
        if(count2>n/3) ans.push_back(c2);
        return ans;
    }
};
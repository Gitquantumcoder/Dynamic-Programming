class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp(n,0);
        for(int i=0;i<n;i++){
            temp[i]=nums[i]*nums[i];
        }
        sort(temp.begin(),temp.end(),greater<int>());
        int st=0,end=n-1;
        long long ans=0;
        while(st<end){
            ans+=(temp[st]-temp[end]);
            st++;
            end--;
        }
        if(n%2!=0){
            ans+=temp[st];
        }
        return ans;
    }
};
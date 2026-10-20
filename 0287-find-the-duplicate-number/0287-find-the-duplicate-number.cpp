class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int ,int>mp;
        int ans=-1;
        for(int it:nums){
            mp[it]++;
        }
        for(auto it:mp){
            if(it.second>1){
                ans=it.first;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int total(string s){
        int sum=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                sum+=i;
            }
        }
        return sum;
    }
    void helper(int idx,string &temp, int n,int k,vector<string>&ans){
        if(idx>=n){
            if(total(temp)<=k){
                ans.push_back(temp);
                
            }
            return;
        }
        temp[idx]='0';
        helper(idx+1,temp,n,k,ans);
        temp[idx]='1';
        if(idx==0||temp[idx-1]!='1'){
            helper(idx+1,temp,n,k,ans);
        }
        temp[idx]='0';
            }
    vector<string> generateValidStrings(int n, int k) {
        string temp(n,'0');
        vector<string>output;;
        helper(0,temp,n,k,output);
        return output;
    }
};
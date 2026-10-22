class Solution {
public:
    void backtrack(vector<string>&ans,string &curr,int n){
        if(curr.size()==n){
            ans.push_back(curr);
            return;
        }
        for(char ch='a';ch<='c';ch++){
            if(!curr.empty() && ch==curr.back()) continue;

            curr.push_back(ch);
            backtrack(ans,curr,n);
            curr.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        vector<string>ans;
        string curr;
        backtrack(ans,curr,n);
        if(ans.size()>=k){
            return ans[k-1];
        }
        return "";
    }
};
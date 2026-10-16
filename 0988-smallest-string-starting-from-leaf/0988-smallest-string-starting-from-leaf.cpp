/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string ans="";
    string temp="";
    void dfs(TreeNode*root,string &temp,string &ans){
        if(root==NULL) return;
        temp.push_back(root->val+'a');
        if(root->left==NULL && root->right==NULL){
            reverse(temp.begin(),temp.end());
            if(ans=="") ans=temp;
            if(temp<ans){
                ans=temp;
            }
            reverse(temp.begin(),temp.end());
        }
        
        dfs(root->left,temp,ans);
        dfs(root->right,temp,ans);
        temp.pop_back();
        return;

    }
    string smallestFromLeaf(TreeNode* root) {
        dfs(root,temp,ans);
        return ans;

    }
};
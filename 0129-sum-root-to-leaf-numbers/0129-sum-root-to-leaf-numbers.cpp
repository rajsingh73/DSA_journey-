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
    void solve(TreeNode* root,int &sum,string val){
        if(root->right==NULL && root->left==NULL){
            val.push_back(root->val+'0');
            sum+=stoi(val);
            return;
        }
        if(root->left){
            val.push_back(root->val+'0');
            solve(root->left,sum,val);
            val.pop_back();
        }
        if(root->right){
            val.push_back(root->val+'0');
            solve(root->right,sum,val);
            val.pop_back();
        }
    }
    int sumNumbers(TreeNode* root) {
        int ans=0;
        string s="";
        solve(root,ans,s);
        return ans;
        
    }
};
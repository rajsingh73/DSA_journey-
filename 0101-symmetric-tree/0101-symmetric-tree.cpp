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
    void solve(TreeNode * first,TreeNode* second,bool & ans){
        if(ans==false) return;
        if(first==NULL && second==NULL) return;
        if(first==NULL || second==NULL){
            ans=false;
            return;
        }
        if(first->val!=second->val){
            ans=false;
            return;
        }
        solve(first->left,second->right,ans);
        solve(first->right,second->left,ans);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        bool ans=true;
        solve(root->left,root->right,ans);
        return ans;
        
    }
};
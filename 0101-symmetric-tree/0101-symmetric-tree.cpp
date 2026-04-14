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
        if(first->val!=second->val) ans=false;
        if(first->left && second->right) solve(first->left,second->right,ans);
        else if(first->left) ans=false;
        else if(second->right) ans=false;
        if(first->right && second->left) solve(first->right,second->left,ans);
        else if(first->right) ans=false;
        else if(second->left) ans=false;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        bool ans=true;
        if(root->left && root->right) solve(root->left,root->right,ans);
        else if(root->left) return false;
        else if(root->right) return false;
        return ans;
        
    }
};
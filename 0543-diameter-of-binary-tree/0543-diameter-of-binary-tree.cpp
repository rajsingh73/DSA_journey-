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
    int solve(TreeNode* root,int & ans){
        if(root==NULL) return 0;
        int right=solve(root->right,ans);
        int left=solve(root->left,ans);
        ans=max(ans,right+left);
        return 1+max(right,left);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        int height=solve(root,ans);
        return ans;
    }
};
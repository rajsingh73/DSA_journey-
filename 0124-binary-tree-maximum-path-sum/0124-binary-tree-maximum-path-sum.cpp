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
        int left=solve(root->left,ans);
        int right=solve(root->right,ans);
        int first=0;
        int second=0;
        if(left<0){
            first=0;
        }
        else{
            first=left;
        }
        if(right<0){
            second=0;
        }
        else{
            second=right;
        }

        ans=max(ans,root->val+first+second);
        return root->val+max(first,second);
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        int val=solve(root,ans);
        return ans;
        
    }
};
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
    int val(TreeNode* root,int maxi){
        if(root==NULL) return 0;
        int ans=0;
        if(root->val>=maxi) ans++;
        ans=ans+val(root->left,max(maxi,root->val))+val(root->right,max(maxi,root->val));
        return ans;
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL) return 0;
        return val(root,root->val);
    }
};
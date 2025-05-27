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
    int solve(TreeNode* root,bool & val){
        if(val==false) return 0;
        if(root==NULL) return 0;
        int left=1+solve(root->left,val);
        int right=1+solve(root->right,val);
        if(max(left,right)-min(left,right)>1) val=false;
        return max(left,right);
    }

    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        bool v=true;
        int vi=solve(root,v);
        return v;
        
    }
};
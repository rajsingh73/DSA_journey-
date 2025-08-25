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
    int check(TreeNode * root,int targetSum,int act){
        if(root==NULL) return 0;
        int ans=0;
        act=act+root->val;
        if(targetSum==act) ans++;
        return ans+check(root->right,targetSum,act)+check(root->left,targetSum,act);

    }
    int val(TreeNode * root,int targetSum){
        if(root==NULL) return 0;
        int ans=0;
        ans+=check(root,targetSum,0);
        return ans+val(root->left,targetSum)+val(root->right,targetSum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        return val(root,targetSum);
        
    }
};
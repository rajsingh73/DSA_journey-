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
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        TreeNode * head=root;
        if(head->left){
            if(head->left->val>=head->val) return false;
        }
        if(head->right){
            if(head->right->val<=head->val) return false;
        }
        bool lefti=isValidBST(head->left);
        bool righti=isValidBST(head->right);
        return lefti&& righti;

        
    }
};
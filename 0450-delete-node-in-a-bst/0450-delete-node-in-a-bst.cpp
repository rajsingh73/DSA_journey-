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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val==key){
            return deleteN(root);
        }
        root->left=deleteNode(root->left,key);
        root->right=deleteNode(root->right,key);
        return root;
    }
    TreeNode * findright(TreeNode * root){
        if(root->right==NULL) return root;
        return findright(root->right);
    }
    TreeNode* deleteN(TreeNode * root){
        if(root->left==NULL) return root->right;
        TreeNode * rightmost=findright(root->left);
        rightmost->right=root->right;
        return root->left;
    }
};
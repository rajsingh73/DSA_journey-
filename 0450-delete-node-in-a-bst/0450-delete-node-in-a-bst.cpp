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
    TreeNode * find(TreeNode * root,int key){
        if(root==NULL) return NULL;
        if(root->right && root->right->val==key) return root;
        if(root->left && root->left->val==key) return root;
        TreeNode * left=find(root->left,key);
        TreeNode * right=find(root->right,key);
        if(left==NULL) return right;;
        return left;;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val==key){
            return deleteN(root);
        }
        TreeNode * f=find(root,key);
        if(f==NULL) return root;
        if(f->left && f->left->val==key) f->left=deleteN(f->left);
        else f->right=deleteN(f->right);
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
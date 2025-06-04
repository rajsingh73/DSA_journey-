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
    TreeNode* solve(TreeNode* root){
        if(root->left==NULL) return root->right;
        if(root->right==NULL) return root->left;
        TreeNode * findleftrigh=findleftright(root->left);
        findleftrigh->right=root->right;
        return root->left;
    }
    TreeNode * findleftright(TreeNode * root){
        TreeNode * head=root;
        while(head->right!=NULL){
            head=head->right;
        }
        return head;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val==key){
            return solve(root);
        }
        root->left=deleteNode(root->left,key);
        root->right=deleteNode(root->right,key);
        return root;
    }
};
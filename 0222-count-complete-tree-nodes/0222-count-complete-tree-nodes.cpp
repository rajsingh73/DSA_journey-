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
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int left=findleft(root);
        int right=findright(root);
        if(left==right) return pow(2,left)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
    int findleft(TreeNode* root){
        int height=0;
        while(root!=NULL){
            root=root->left;
            height++;
        }
        return height;
    }
    int findright(TreeNode* root){
        int height=0;
        while(root!=NULL){
            root=root->right;
            height++;
        }
        return height;
    }
};
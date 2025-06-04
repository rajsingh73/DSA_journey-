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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode * head=root;
        if(head==NULL) return new TreeNode(val);
        while(head){
            if(head->val>val){
                if(head->left==NULL){
                    head->left=new TreeNode(val);
                    break;
                }
                else{
                    head=head->left;
                }
            }
            else{
                if(head->right==NULL){
                    head->right=new TreeNode(val);
                    break;
                }
                else head=head->right;
            }
        }
        return root;

        
    }
};
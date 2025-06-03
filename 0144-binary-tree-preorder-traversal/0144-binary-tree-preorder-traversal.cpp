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
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode * head=root;
        vector<int> preorder;
        while(head!=NULL){
            if(head->left==NULL){
                preorder.push_back(head->val);
                head=head->right;
            }
            else{
                TreeNode * prev=head->left;
                while(prev->right && prev->right !=head){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=head;
                    preorder.push_back(head->val);
                    head=head->left;
                }
                else{
                    prev->right=NULL;
                    head=head->right;
                }
            }
        }
        return preorder;
        
    }
};
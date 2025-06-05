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
    void recoverTree(TreeNode* root) {
        TreeNode * first=NULL;
        TreeNode *second=NULL;
        TreeNode * middle=NULL;
        TreeNode * head=root;
        TreeNode * prev=NULL;
        while(head){
            if(head->left==NULL){
                if(prev==NULL){
                    prev=head;
                    head=head->right;
                }
                else{
                    if(prev->val>head->val){
                        if(first==NULL){
                            first=prev;
                            middle=head;
                        }
                        else second=head;
                    }
                    prev=head;
                    head=head->right;
                }
            }
            else{
                TreeNode * p=head->left;
                while(p->right && p->right!=head) p=p->right;
                if(p->right==NULL){
                    p->right=head;
                    head=head->left;
                }
                else{
                    p->right=NULL;
                    if(prev==NULL){
                        prev=head;
                        head=head->right;
                    }
                    else{
                    if(prev->val>head->val){
                        if(first==NULL){
                            first=prev;
                            middle=head;
                        }
                        else second=head;
                    }
                    prev=head;
                    head=head->right;
                    }
                }
            }
        }
        if(second){
            swap(first->val,second->val);
        }
        else{
            swap(first->val,middle->val);
        }
        
    }
};
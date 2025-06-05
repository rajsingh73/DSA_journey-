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
    void pushleft(TreeNode* root,stack<TreeNode*> &stl){
        if(root==NULL) return;
        TreeNode * temp=root;
        while(temp){
            stl.push(temp);
            temp=temp->left;
        }
    }
    void pushright(TreeNode * root,stack<TreeNode*> & str){
        if(root==NULL) return;
        TreeNode * temp=root;
        while(temp){
            str.push(temp);
            temp=temp->right;
        }
    }
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> stl;
        stack<TreeNode*> str;
        pushleft(root,stl);
        pushright(root,str);
        while(!stl.empty() && !str.empty()){
            TreeNode * templ=stl.top();
            TreeNode * tempr=str.top();
            if(templ==tempr) break;
            int val=templ->val+tempr->val;
            if(val==k) return true;
            if(val<k){
                stl.pop();
                pushleft(templ->right,stl);
            }
            else{
                str.pop();
                pushright(tempr->left,str);
            }
        }
        return false;
        
    }
};
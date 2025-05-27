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
    void solve(TreeNode * p,TreeNode * q,bool & ans){
        if(ans==false) return;
        if(p==NULL && q==NULL){
            ans=true;
            return;
        }
        if(p==NULL || q==NULL){
            ans=false;
            return;
        }
        if(p->val!=q->val){
            ans=false;
            return;
        }
        solve(p->left,q->left,ans);
        solve(p->right,q->right,ans);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool ans=true;
        solve(p,q,ans);
        return ans;


        
    }
};
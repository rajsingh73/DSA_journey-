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
    void a(TreeNode  * root,char prev,int &ans,int count){
        if(root==NULL){
            ans=max(ans,count);
            return;
        }
        if(prev=='L'){
            a(root->right,'R',ans,count+1);
            a(root->left,'L',ans,0);
        }
        else{
            a(root->left,'L',ans,count+1);
            a(root->right,'R',ans,0);
        }
    }
    int longestZigZag(TreeNode* root) {
        int ans=0;
        a(root->right,'R',ans,0);
        a(root->left,'L',ans,0);
        return ans;
        
    }
};
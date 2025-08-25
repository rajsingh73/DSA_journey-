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
    void left(TreeNode * root,vector<int> & ans){
        if(root==NULL) return;
        if(root->right==NULL && root->left ==NULL){
            ans.push_back(root->val);
            return;
        }
        left(root->left,ans);
        left(root->right,ans);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> first;
        vector<int> second;
        left(root1,first);
        left(root2,second);
        for(auto it: first) cout<<it<<" ";
        cout<<endl;
        for(auto it: second) cout<<it<<" ";
        return first==second; 
    }
};
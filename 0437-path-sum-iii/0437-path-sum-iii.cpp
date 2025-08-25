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
    int val(TreeNode * root,int targetsum,map<long long,int> mp,int pre){
        if(root==NULL) return 0;
        pre+=root->val;
        int ans=0;
        if(mp.count(pre-targetsum)) ans+=mp[pre-targetsum];
        mp[pre]++;
        ans+=val(root->left,targetsum,mp,pre);
        ans+=val(root->right,targetsum,mp,pre);
        return ans;
    }
    int pathSum(TreeNode* root, int targetsum) {
        map<long long,int> mp;
        mp[0]=1;
        return val(root,targetsum,mp,0);
        
    }
};
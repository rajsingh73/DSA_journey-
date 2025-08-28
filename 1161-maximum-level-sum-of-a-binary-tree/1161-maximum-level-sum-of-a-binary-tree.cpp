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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        int level=1;
        int ans=0;
        int sum=INT_MIN;
        q.push(root);
        while(q.size()){
            int size=q.size();
            int ls=0;
            for(int i=0;i<size;i++){
                TreeNode * temp=q.front();
                q.pop();
                ls+=temp->val;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            if(ls>sum){
                sum=ls;
                ans=level;
            }
            level++;
        }
        return ans;
    }
};
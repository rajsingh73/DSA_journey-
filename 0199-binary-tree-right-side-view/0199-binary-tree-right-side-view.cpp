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
    vector<int> rightSideView(TreeNode* root) {
        map<int,int> mp;
        queue<pair<TreeNode*,int>> q;
        vector<int> ans;
        if(root==NULL) return ans;
        q.push({root,0});
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                pair<TreeNode*,int> temp=q.front();
                q.pop();
                TreeNode * te=temp.first;
                int value=temp.second;
                if(te->left) q.push({te->left,value+1});
                if(te->right) q.push({te->right,value+1});
                mp[value]=te->val;
            }
        }
        for(auto [firs,second]:mp){
            ans.push_back(second);
        }
        return ans;
    }
};
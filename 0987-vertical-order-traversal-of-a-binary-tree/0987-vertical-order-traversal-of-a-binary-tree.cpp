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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<int>>mp;
        queue<pair<TreeNode*,int>> q;
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        q.push({root,0});
        int lowest=INT_MAX;
        int maxi=INT_MIN;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                pair<TreeNode*, int> temp=q.front();
                q.pop();
                TreeNode * te=temp.first;
                int value=temp.second;
                if(te->left) q.push({te->left,value-1});
                if(te->right) q.push({te->right,value+1});
                mp[value].push_back(te->val);
                lowest=min(lowest,value);
                maxi=max(maxi,value);
            }
        }
        for(int i=lowest;i<=maxi;i++){
            sort(mp[i].begin(),mp[i].end());
            ans.push_back(mp[i]);
        }
        return ans;
    }
};
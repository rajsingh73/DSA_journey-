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
        map<int,map<int,vector<int>>>mp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        q.push({root,{0,0}});
        int lowest=INT_MAX;
        int maxi=INT_MIN;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                pair<TreeNode*, pair<int,int>> temp=q.front();
                q.pop();
                TreeNode *te=temp.first;
                int vertical=temp.second.first;
                int horizontal=temp.second.second;
                if(te->left) q.push({te->left,{vertical-1,horizontal+1}});
                if(te->right) q.push({te->right,{vertical+1,horizontal+1}});
                mp[vertical][horizontal].push_back(te->val);
            }
        }
        for(auto [first,second]:mp){
            vector<int> temp;
            for(auto [n,v]:second){
                sort(v.begin(),v.end());
                temp.insert(temp.end(),v.begin(),v.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
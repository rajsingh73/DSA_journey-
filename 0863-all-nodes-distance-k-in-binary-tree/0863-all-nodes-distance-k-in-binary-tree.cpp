/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void marparent(TreeNode * root,unordered_map<TreeNode*,TreeNode*> &mp){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode * temp=q.front();
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                    mp[temp->left]=temp;
                }
                if(temp->right){
                    q.push(temp->right);
                    mp[temp->right]=temp;
                }
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> mp;
        marparent(root,mp);
        unordered_map<TreeNode *,bool> visited;
        queue<TreeNode*>  q;
        q.push(target);
        visited[target]=true;
        int curr_level=0;
        while(!q.empty()){
            int size=q.size();
            if(curr_level==k) break;
            for(int i=0;i<size;i++){
                TreeNode * temp=q.front();
                q.pop();
                if(temp->left && !visited[temp->left]){
                    q.push(temp->left);
                    visited[temp->left]=true;
                }
                if(temp->right && !visited[temp->right]){
                    q.push(temp->right);
                    visited[temp->right]=true;
                }
                if(mp[temp] && !visited[mp[temp]]){
                    q.push(mp[temp]);
                    visited[mp[temp]]=true;
                }
            }
            curr_level++;
        }
        vector<int> ans;
        while(!q.empty()){
            TreeNode * temp=q.front();
            q.pop();
            ans.push_back(temp->val);
        }
        return ans;
        
    }
};
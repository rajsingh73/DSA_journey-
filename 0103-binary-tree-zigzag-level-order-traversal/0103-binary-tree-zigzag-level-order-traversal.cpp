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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> st;
        st.push(root);
        int count=0;
        while(!st.empty()){
            int size=st.size();
            vector<int> v;
            for(int i=0;i<size;i++){
                TreeNode * temp=st.front();
                st.pop();
                if(temp->left) st.push(temp->left);
                if(temp->right) st.push(temp->right);
                v.push_back(temp->val);
            }
            if(count%2!=0) reverse(v.begin(),v.end());
            count++;
            ans.push_back(v);
        }
        return ans;
        
    }
};
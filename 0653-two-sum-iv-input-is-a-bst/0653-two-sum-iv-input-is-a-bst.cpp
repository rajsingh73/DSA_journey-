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
    bool findTarget(TreeNode* root, int k) {
        map<int,int> mp;
        TreeNode * head=root;
        bool ans=false;
        while(head){
            if(head->left==NULL){
                int rem=k-head->val;
                if(mp.find(rem)!=mp.end()) ans=true;
                mp[head->val]++;
                head=head->right;
            }
            else{
                TreeNode * prev=head->left;
                while(prev->right && prev->right!=head) prev=prev->right;
                if(prev->right==NULL){
                    prev->right=head;
                    head=head->left;
                }
                else{
                    prev->right=NULL;
                    int rem=k-head->val;
                    if(mp.find(rem)!=mp.end()) ans=true;
                    mp[head->val]++;
                    head=head->right;
                }
            }
        }
        return ans;

        
    }
};
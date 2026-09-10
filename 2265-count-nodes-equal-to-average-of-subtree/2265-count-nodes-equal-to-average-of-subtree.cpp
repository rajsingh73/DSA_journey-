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
    vector<int> solve(TreeNode * root,int & ans){
        int sum=root->val;
        int number=1;
        if(root->right==NULL) sum+=0;
        else{
            vector<int> temp=solve(root->right,ans);
            sum+=temp[0];
            number+=temp[1];
        }
        if(root->left==NULL) sum+=0;
        else{
            vector<int> temp=solve(root->left,ans);
            sum+=temp[0];
            number+=temp[1];   
        }
        int average=sum/number;
        if(average==root->val) ans++;
        return {sum,number};

    }
    int averageOfSubtree(TreeNode* root) {
        if(root==NULL) return 0;
        int ans=0;
        vector<int> temp=solve(root,ans);
        return ans;
        
    }
};
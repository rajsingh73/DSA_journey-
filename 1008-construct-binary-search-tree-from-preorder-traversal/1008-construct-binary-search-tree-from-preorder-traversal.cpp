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
    TreeNode * solve(vector<int> &preorder,int low,int high){
        if(low>high) return NULL;
        TreeNode * root= new TreeNode(preorder[low]);
        int count=low+1;
        while(count<=high && preorder[count]<preorder[low]) count++;
        root->left=solve(preorder,low+1,count-1);
        root->right=solve(preorder,count,high);
        return root;

    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return solve(preorder,0,preorder.size()-1);
    }
};
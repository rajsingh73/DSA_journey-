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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        TreeNode * root=build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);   
        return root;
    }
    TreeNode * build(vector<int> & preorder,int startp,int endp,vector<int> & inorder,int starti,int endi,map<int,int> &mp){
        if(starti>endi || startp>endp) return NULL;
        TreeNode * root=new TreeNode(preorder[startp]);
        int val=mp[preorder[startp]];
        int leftval=val-starti;
        root->left=build(preorder,startp+1,startp+leftval,inorder,starti,val-1,mp);
        root->right=build(preorder,startp+leftval+1,endp,inorder,val+1,endi,mp);
        return root;
    }
};
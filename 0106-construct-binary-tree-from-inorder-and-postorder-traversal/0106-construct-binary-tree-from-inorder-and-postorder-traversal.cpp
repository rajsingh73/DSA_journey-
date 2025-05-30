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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++) mp[inorder[i]]=i;
        TreeNode * root = build(postorder,postorder.size()-1,0,inorder,0,inorder.size()-1,mp);
        return root;
    }
    TreeNode * build(vector<int> & postorder,int startp,int endp,vector<int> & inorder,int starti,int endi ,map<int,int> & mp){
        if(startp<endp || starti>endi) return NULL;
        TreeNode * root=new TreeNode(postorder[startp]);
        int val=mp[postorder[startp]];
        int rightval=endi-val;
        root->left=build(postorder,startp-rightval-1,endp,inorder,starti,val-1,mp);
        root->right=build(postorder,startp-1,startp-rightval,inorder,val+1,endi,mp);
        return root;
    }
};
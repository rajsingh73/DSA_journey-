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
class BSTIterator {
public:
    stack<TreeNode *> st;
    void pushleft(TreeNode * root){
        if(root==NULL) return;
        while(root){
            st.push(root);
            root=root->left;
        }
    }
    BSTIterator(TreeNode* root) {
        pushleft(root);
    }
    
    int next() {
        if(st.size()==0) return -1;
        TreeNode * temp=st.top();
        st.pop();
        pushleft(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        if(st.size()==0) return false;
        return true;

        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
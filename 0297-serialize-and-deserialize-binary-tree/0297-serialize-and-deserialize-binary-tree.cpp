/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "";
        string s="";
        queue<TreeNode*> q;
        q.push(root);
        s+=to_string(root->val)+',';
        while(!q.empty()){
            int size=q.size();
            for(int k=0;k<size;k++){
                TreeNode * temp=q.front();
                q.pop();
                if(temp->left){
                    s+=to_string(temp->left->val)+',';
                    q.push(temp->left);
                }
                else{
                    s+="#,";
                }
                if(temp->right){
                    s+=to_string(temp->right->val)+',';
                    q.push(temp->right);
                }
                else{
                    s+="#,";
                }
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        if(s.empty()) return NULL;
        vector<string> st;
        int i=0;
        while(i<s.size()){
            string temp="";
            while(i<s.size() && s[i]!=','){
                temp+=s[i];
                i++;
            }
            st.push_back(temp);
            i++;
        }
        TreeNode * root=new TreeNode(stoi(st[0]));
        i=1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty() && i<st.size()){
            TreeNode * te=q.front();
            q.pop();
            string temp=st[i];
            if(temp=="#"){
                te->left=NULL;
            }
            else{
                te->left= new TreeNode(stoi(temp));
                q.push(te->left);
            }
            i++;
            if(i<st.size()){
                temp=st[i];
                if(temp=="#") te->right=NULL;
                else{
                    te->right=new TreeNode(stoi(temp));
                    q.push(te->right);
                }
            }
            i++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
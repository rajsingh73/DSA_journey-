struct Node{
    Node * links[26];
    bool flag=false;
    bool contain(char ch){
        return links[ch-'a']!=NULL;
    }
    void put(char ch,Node * node){
        links[ch-'a']=node;
    }
    Node *  get(char ch) {
        return links[ch-'a'];
    }
    void setend() {
        flag=true;
    }
};
class Tries{
    public: 
        Node * root;
        Tries(){
            root=new Node();
        }
        void insert(string word){
            Node * node=root;
            for(int i=0;i<word.size();i++){
                if(!node->contain(word[i])) node->put(word[i],new Node());
                node=node->get(word[i]);
            }
            node->setend();
        }
        Node* realnode(string word){
            Node  * node=root;
            for(int i=0;i<word.size();i++){
                if(!node->contain(word[i])) return NULL;
                node=node->get(word[i]);
            }
            return node;
        }
        void solve(Node * node,string s,vector<string> & temp){
            if(temp.size()==3) return;
            if(node==NULL) return;
            if(node->flag==true) temp.push_back(s);
            for(int i=0;i<26;i++){
                if(temp.size()==3) return;
                if(node->contain(i+'a')){
                    s.push_back(i+'a');
                    solve(node->get(i+'a'),s,temp);
                    s.pop_back();
                }
            }
        }
};
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Tries t;
        for(auto it: products){
            t.insert(it);
        }
        string s="";
        vector<vector<string>> ans;
        for(int i=0;i<searchWord.size();i++){
            s+=searchWord[i];
            Node * returnnode=t.realnode(s);
            vector<string> temp;
            if(returnnode){
                t.solve(returnnode,s,temp);
            }
            ans.push_back(temp);
        }
        return ans;
        
    }
};
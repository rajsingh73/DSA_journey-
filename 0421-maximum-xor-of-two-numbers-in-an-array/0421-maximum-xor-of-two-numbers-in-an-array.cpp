struct Node{
    Node * links[2];
    bool contain(int num){
        return links[num]==NULL;
    }
    void put(int num,Node * node){
        links[num]=node;
    }
    Node * get(int num){
        return links[num];
    }
};
class Trie{
    private:
        Node * root;
    public: 
        Trie(){
            root=new Node();
        }
        void insert(int num){
            Node * node=root;
            for(int i=31;i>=0;i--){
                int bit=(num>>i) &1;
                if(node->contain(bit)){
                    node->put(bit,new Node());
                }
                node=node->get(bit);
            }
        }
        int maxval(int num){
            int ans=0;
            Node * node=root;
            for(int i=31;i>=0;i--){
                int bit=(num>>i) & 1;
                if(!node->contain(1-bit)){
                    ans=ans|(1<<i);
                    node=node->get(1-bit);
                }
                else node=node->get(bit);
            }
            return ans;
        }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie t;
        for(auto it: nums) t.insert(it);
        int ans=0;
        for(auto it: nums){
            ans=max(ans,t.maxval(it));
        }
        return ans;
        
    }
};
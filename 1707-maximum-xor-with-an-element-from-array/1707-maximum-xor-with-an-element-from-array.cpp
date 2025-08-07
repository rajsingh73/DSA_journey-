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
    static bool comp(vector<int> first,vector<int> second){
        return first[1]<second[1];
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<vector<int>> v;
        for(int i=0;i<queries.size();i++){
            v.push_back({queries[i][0],queries[i][1],i});
        }
        sort(v.begin(),v.end(),comp);
        sort(nums.begin(),nums.end());
        int n=queries.size();
        vector<int> ans(n);
        int j=0;
        Trie t;
        for(int i=0;i<n;i++){
            int attack=v[i][0];
            int limit=v[i][1];
            int index=v[i][2];
            while(j<nums.size() && nums[j]<=limit){
                t.insert(nums[j]);
                j++;
            }
            if(j==0) ans[index]=-1;
            else{
                int maxi=t.maxval(attack);
                ans[index]=maxi;
            }
        }
        return ans;

        
    }
};
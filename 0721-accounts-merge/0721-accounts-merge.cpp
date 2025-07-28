class DistJointset{
    public:
        vector<int> rank,parent,size;
        DistJointset(int v){
            rank.resize(v+1,0);
            parent.resize(v+1);
            size.resize(v+1,1);
            for(int i=0;i<=v;i++) parent[i]=i;
        }
        int findUpar(int u){
            if(u==parent[u]) return u;
            return parent[u]=findUpar(parent[u]);
        }
        void unionbyrank(int u,int v){
            int ul_u=findUpar(u);
            int ul_v=findUpar(v);
            if(ul_u==ul_v) return;
            if(rank[ul_v]<rank[ul_u]){
                parent[ul_v]=ul_u;
            }
            else if(rank[ul_v]>rank[ul_u]){
                parent[ul_u]=ul_v;
            }
            else{
                parent[ul_v]=ul_u;
                rank[ul_u]++;
            }
        }
        void unionbysize(int u,int v){
            int ul_u=findUpar(u);
            int ul_v=findUpar(v);
            if(ul_u==ul_v) return;
            if(size[ul_u]<size[ul_v]){
                parent[ul_u]=ul_v;
                size[ul_v]+=size[ul_u];
            }
            else{
                parent[ul_v]=ul_u;
                size[ul_u]+=size[ul_v];
            }
        }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n=accounts.size();
        DistJointset ds(n);
        map<string,int> mp;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mp.find(mail)!=mp.end()){
                    ds.unionbysize(i,mp[mail]);
                }
                else mp[mail]=i;
            }
        }
        vector<string> node[n];
        for(auto it: mp){
            int u=ds.findUpar(it.second);
            node[u].push_back(it.first);
        }
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(node[i].size()==0) continue;
            vector<string> temp;
            sort(node[i].begin(),node[i].end());
            temp.push_back(accounts[i][0]);
            for(auto it: node[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
        
    }
};
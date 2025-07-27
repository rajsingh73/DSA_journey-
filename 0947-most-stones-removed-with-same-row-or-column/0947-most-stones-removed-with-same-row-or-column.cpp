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
    int removeStones(vector<vector<int>>& stones) {
        int maxrow=0;
        int n=stones.size();
        int maxcol=0;
        for(auto it: stones){
            maxrow=max(maxrow,it[0]);
            maxcol=max(maxcol,it[1]);
        }
        DistJointset ds(maxrow+maxcol+2);
        unordered_map<int,int> mp;
        for(auto it: stones){
            int nr=it[0];
            int nc=it[1]+maxrow+1;
            ds.unionbysize(nr,nc);
            mp[nr]=1;
            mp[nc]=1;
        }
        int count=0;
        for(auto it: mp){
            if(ds.findUpar(it.first)==it.first) count++;
        }
        return n-count;
    }
};
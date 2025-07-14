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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DistJointset ds(n);
        int left=0;
        for(auto it: connections){
            if(ds.findUpar(it[0]) != ds.findUpar(it[1])){
                ds.unionbysize(it[0],it[1]);
            }
            else{
                left++;
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i) count++;
        }
        return left>=count-1? count-1 : -1;
    }
};
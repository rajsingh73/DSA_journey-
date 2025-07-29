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
    bool isvalid(int n,int row,int col){
        return row>=0 && row<n && col>=0 && col<n;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int ans=INT_MIN;
        DistJointset ds(n*n+1);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int dr[4]={-1,0,1,0};
                int dc[4]={0,-1,0,1};
                if(grid[i][j]==1){
                    for(int ind=0;ind<4;ind++){
                        int nrow=i+dr[ind];
                        int ncol=j+dc[ind];
                        if(isvalid(n,nrow,ncol) && grid[nrow][ncol]==1){
                            int val=nrow*n+ncol;
                            int nval=i*n+j;
                            ds.unionbysize(val,nval);
                        }
                    }
                }
            }
        }
        for(int i=0;i<n*n;i++){
            cout<<ds.size[i]<<" ";
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                set<int> st;
                int dr[4]={-1,0,1,0};
                int dc[4]={0,-1,0,1};
                int temp=ds.findUpar(i*n+j);
                st.insert(temp);
                for(int ind=0;ind<4;ind++){
                    int nrow=i+dr[ind];
                    int ncol=j+dc[ind];
                    if(isvalid(n,nrow,ncol) && grid[nrow][ncol]==1){
                        int val=nrow*n+ncol;
                        int p=ds.findUpar(val);
                        st.insert(p);
                    }
                }
                int val=0;
                for(auto it: st){
                    val+=ds.size[it];
                }
                ans=max(ans,val);
                if(ans==n*n) return ans;
            }
        }
        return ans;

        

    }
};
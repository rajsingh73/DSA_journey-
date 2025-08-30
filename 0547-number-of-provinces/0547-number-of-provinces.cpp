class Dist{
    public:
        vector<int> rank,parent,size;
        Dist(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            size.resize(n+1,1);
            for(int i =0;i<n;i++) parent[i]=i;
        }
        int findparent(int n){
            if(n==parent[n]) return n;
            return parent[n]=findparent(parent[n]);
        }
        void unionbysize(int first,int second){
            int firstparent=findparent(first);
            int secondparent=findparent(second);
            if(firstparent==secondparent) return;
            if(size[firstparent]<size[secondparent]){
                parent[firstparent]=secondparent;
                size[secondparent]+=size[firstparent];
            }
            else{
                parent[secondparent]=firstparent;
                size[firstparent]+=size[secondparent];
            }
        }
        void unionbyrank(int first,int second){
            int firstparent=findparent(first);
            int secondparent=findparent(second);
            if(firstparent==secondparent) return;
            if(rank[firstparent]<rank[secondparent]){
                parent[firstparent]=secondparent;
            }
            else if(rank[firstparent]>rank[secondparent]){
                parent[secondparent]=firstparent;
            }
            else{
                parent[firstparent]=secondparent;
                rank[secondparent]++;
            }
        }

};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        Dist d(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    d.unionbysize(i,j);
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(d.parent[i]==i) count++;
        }
        return count;
        
    }
};
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int d) {
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        for(auto it: edges){
            dist[it[0]][it[1]]=it[2];
            dist[it[1]][it[0]]=it[2];
        }
        for(int i=0;i<n;i++) dist[i][i]=0;
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX){
                        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                    }
                }
            }
        }
        int count=n;
        int cityno=-1;
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=0;j<n;j++){
                if(dist[i][j]<=d) c++;
            }
            if(c<=count){
                count=c;
                cityno=i;
            }
        }
        return cityno;
        
    }
};
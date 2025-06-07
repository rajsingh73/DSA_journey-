class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int orange=0;
        int count=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int> (m,0));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    count++;
                    visited[i][j]=1;
                }
                if(grid[i][j]!=0) orange++;
            }
        }
        int ans=0;
        if(count==orange) return 0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                pair<int,int> p=q.front();
                q.pop();
                int row=p.first;
                int col=p.second;
                int nrow=row+1;
                int ncol=col;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && visited[nrow][ncol]==0){
                    q.push({nrow,ncol});
                    visited[nrow][ncol]=1;
                    count++;
                }
                nrow=row;
                ncol=col+1;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && visited[nrow][ncol]==0){
                    q.push({nrow,ncol});
                    visited[nrow][ncol]=1;
                    count++;
                }
                nrow=row-1;
                ncol=col;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && visited[nrow][ncol]==0){
                    q.push({nrow,ncol});
                    visited[nrow][ncol]=1;
                    count++;
                }
                nrow=row;
                ncol=col-1;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && visited[nrow][ncol]==0){
                    q.push({nrow,ncol});
                    visited[nrow][ncol]=1;
                    count++;
                }
            }
            ans++;
        }
        if(count==orange) return ans-1;
        return -1;
        
    }
};
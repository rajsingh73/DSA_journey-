class Solution {
public:
    bool isvalid(int row,int col,int n,int m, vector<vector<int>> & grid,vector<vector<int>> & visited){
        return row>=0 && row<n && col>=0 && col<m && grid[row][col]==1 && visited[row][col]==0;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int orange=0;
        queue<pair<int,int>> q;
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    visited[i][j]=1;
                }
                else if(grid[i][j]==1) orange++;
            }
        }
        int minite=0;
        while(!q.empty()){
            if(orange==0) return minite;
            int size=q.size();
            for(int i=0;i<size;i++){
                auto [row,col] =q.front(); q.pop();
                int dr[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
                for(int j=0;j<4;j++){
                    int nrow=row+dr[j][0];
                    int ncol=col+dr[j][1];
                    if(isvalid(nrow,ncol,n,m,grid,visited)){
                        orange--;
                        q.push({nrow,ncol});
                        visited[nrow][ncol]=1;
                    }
                }
            }
             minite++;
        }
        if(orange==0) return minite;
        return -1;

        
    }
};
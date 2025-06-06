class Solution {
public:
    void solve(vector<vector<char>> & grid,vector<vector<int>> & visited,int row,int col){
        int n=grid.size();
        int m=grid[0].size();
        visited[row][col]=1;
        int nrow=row-1;
        int ncol=col;
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && visited[nrow][ncol]!=1) solve(grid,visited,nrow,ncol);
        nrow=row;
        ncol=col-1;
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && visited[nrow][ncol]!=1) solve(grid,visited,nrow,ncol);
        nrow=row;
        ncol=col+1;
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && visited[nrow][ncol]!=1) solve(grid,visited,nrow,ncol);
        nrow=row+1;
        ncol=col;
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && visited[nrow][ncol]!=1) solve(grid,visited,nrow,ncol);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && visited[i][j]!=1){
                    count++;
                    solve(grid,visited,i,j);
                }
            }
        }
        return count;
        
    }
};
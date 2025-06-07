class Solution {
public:
    void dfs(vector<vector<int>> & grid,vector<vector<int>> & visited,int row,int col,int n,int m){
        if(row<0 || row>=n || col<0 || col>=m || visited[row][col]==1 || grid[row][col]==0) return;
        visited[row][col]=1;
        dfs(grid,visited,row+1,col,n,m);
        dfs(grid,visited,row,col+1,n,m);
        dfs(grid,visited,row-1,col,n,m);
        dfs(grid,visited,row,col-1,n,m);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(grid[i][0]==1) dfs(grid,visited,i,0,n,m);
            if(grid[i][m-1]==1) dfs(grid,visited,i,m-1,n,m);
        }
        for(int i=0;i<m;i++){
            if(grid[0][i]==1) dfs(grid,visited,0,i,n,m);
            if(grid[n-1][i]==1) dfs(grid,visited,n-1,i,n,m);
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0 && grid[i][j]==1) count++;
            }
        }
        return count;
        
    }
};
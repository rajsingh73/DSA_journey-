class Solution {
public:
    int solve(int row,int col,int n,int m,vector<vector<int>> & dp,vector<vector<int>> & grid){
        if(row>=n || col>=m) return 1e9;
        if(row==n-1 && col==m-1) return grid[row][col];
        if(dp[row][col]!=-1) return dp[row][col];
        return dp[row][col]=grid[row][col]+min(solve(row+1,col,n,m,dp,grid),solve(row,col+1,n,m,dp,grid));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return solve(0,0,n,m,dp,grid);

    }
};
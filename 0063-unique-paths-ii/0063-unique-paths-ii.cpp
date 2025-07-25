class Solution {
public:
    int solve(int row,int col,vector<vector<int>> & dp,int n,int m,vector<vector<int>> & obstacleGrid){
        if(row>=n || col>=m) return 0;
        if(obstacleGrid[row][col]==1) return 0;
        if(row==n-1 && col==m-1) return 1;
        if(dp[row][col]!=-1) return dp[row][col];
        return dp[row][col]=solve(row+1,col,dp,n,m,obstacleGrid)+solve(row,col+1,dp,n,m,obstacleGrid);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n= obstacleGrid.size();
        int m= obstacleGrid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(0,0,dp,n,m,obstacleGrid);
    }
};
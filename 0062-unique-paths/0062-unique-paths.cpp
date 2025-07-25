class Solution {
public:
    int solve(int row,int col,vector<vector<int>> & dp,int n,int m){
        if(row==n-1 && col==m-1) return 1;
        if(row>=n || col>=m) return 0;
        if(dp[row][col]!=-1) return dp[row][col];
        return dp[row][col]=solve(row+1,col,dp,n,m)+solve(row,col+1,dp,n,m);
    }
    int uniquePaths(int n, int m) {
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(0,0,dp,n,m);
    }
};
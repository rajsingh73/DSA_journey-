class Solution {
public:
    bool invalid(int n,int m,int row,int col){
        return row>=n || n<0 || col>=m || col<0;
    }
    int solve(int n,int m,int row,int col,vector<vector<int>> & dp){
        if(invalid(n,m,row,col)) return 0;
        if(row==n-1 && col==m-1) return 1;
        if(dp[row][col]!=-1) return dp[row][col];
        return dp[row][col]=solve(n,m,row+1,col,dp)+solve(n,m,row,col+1,dp);

    }
    int uniquePaths(int n, int m) {
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n,m,0,0,dp);
    }
};
class Solution {
public:
    int solve(vector<vector<int>> & grid,int i,int j,vector<vector<int>> & dp){
        if(i==0 && j==0) return grid[i][j];
        if(i<0 || j<0) return INT_MAX-40000;
        if(dp[i][j]!=-1) return dp[i][j];
        int top=grid[i][j]+solve(grid,i-1,j,dp);
        int left=grid[i][j]+solve(grid,i,j-1,dp);
        cout<<min(top,left)<<" ";
        return dp[i][j]= min(top,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0) dp[i][j]=grid[i][j];
                else{
                    int top=INT_MAX-40000;
                    int left=INT_MAX-40000;
                    if(i>0) top=grid[i][j]+dp[i-1][j];
                    if(j>0) left=grid[i][j]+dp[i][j-1];
                    dp[i][j]=min(top,left);
                }
            }
        }
        return dp[n-1][m-1];
    }
};
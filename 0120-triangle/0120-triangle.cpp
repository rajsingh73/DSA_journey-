class Solution {
public:
    int solve(vector<vector<int>> & triangle,int i,int j,vector<vector<int>> dp){
        if(j>=triangle[i].size()){
            return 1e9;
        }
        if(i==triangle.size()-1){
            return triangle[i][j];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int bottom=triangle[i][j]+solve(triangle,i+1,j,dp);
        int dia=triangle[i][j]+solve(triangle,i+1,j+1,dp);
        return dp[i][j]= min(bottom,dia);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[0].size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(triangle,0,0,dp);

    }
};
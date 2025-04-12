class Solution {
public:
    int solve(vector<vector<int>> & triangle,int i,int j,vector<vector<int>>& dp){
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
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<i+1;j++){
                if(i==0 && j==0) dp[i][j]=triangle[i][j];
                else{
                    int top=1e9;
                    if(j<i) top=triangle[i][j]+dp[i-1][j];
                    int dia=1e9;
                    if(j>0) dia=triangle[i][j]+dp[i-1][j-1];
                    dp[i][j]=min(top,dia);
                }
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,dp[n-1][i]);
        }
        return ans;
    }
};
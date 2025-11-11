class Solution {
public:
    int solve(vector<string>&strs,int i,int m,int n,vector<vector<vector<int>>> & dp){
        if(i==strs.size()) return 0;
        if(dp[i][m][n]!=-1) return dp[i][m][n];
        int countn=0;
        int countm=0;
        for(auto it:strs[i]){
            if(it=='1') countn++;
            else countm++;
        }
        int take=0;
        if(m-countm<0 || n-countn<0) take=0;
        else take=1+solve(strs,i+1,m-countm,n-countn,dp);
        int nottake=solve(strs,i+1,m,n,dp);
        return  dp[i][m][n]=max(take,nottake);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size=strs.size();
        vector<vector<vector<int>>> dp(size,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return solve(strs,0,m,n,dp);
    }
};
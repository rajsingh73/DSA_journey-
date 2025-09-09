class Solution {
public:
    int solve(int n,int m,int row,int col,string &text1,string &text2,vector<vector<int>> & dp){
        if(row<0 || col<0) return 0;
        if(dp[row][col]!=-1) return dp[row][col];
        if(text1[row]==text2[col]) return dp[row][col] = 1+ solve(n,m,row-1,col-1,text1,text2,dp);
        return dp[row][col]=max(solve(n,m,row-1,col,text1,text2,dp),solve(n,m,row,col-1,text1,text2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n,m,n-1,m-1,text1,text2,dp);
    }
};
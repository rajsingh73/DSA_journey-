class Solution {
public:
    int solve(string & word1,string & word2,int row,int col,vector<vector<int>> & dp){
        if(row<0) return col+1;
        if(col<0) return row+1;
        if(dp[row][col]!=-1) return dp[row][col];
        if(word1[row]==word2[col]) return dp[row][col]=solve(word1,word2,row-1,col-1,dp);
        int first=1+solve(word1,word2,row,col-1,dp);
        int second=1+solve(word1,word2,row-1,col-1,dp);
        int third=1+solve(word1,word2,row-1,col,dp);
        return dp[row][col]=min({first,second,third});
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(word1,word2,n-1,m-1,dp);
    }
};
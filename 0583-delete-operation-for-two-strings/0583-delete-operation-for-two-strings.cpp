class Solution {
public:
    int solve(string & word1,string &word2,int index1,int index2,vector<vector<int>> & dp){
        if(index1<0 || index2<0) return 0;
        if(dp[index1][index2]!=-1) return dp[index1][index2];
        if(word1[index1]==word2[index2]) return dp[index1][index2]=1+solve(word1,word2,index1-1,index2-1,dp);
        else return dp[index1][index2]=max(solve(word1,word2,index1-1,index2,dp),solve(word1,word2,index1,index2-1,dp));
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        int val=solve(word1,word2,n-1,m-1,dp);
        return (n+m)-(2*val);
    }
};
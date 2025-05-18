class Solution {
public:
    int solve(string & word1,string & word2,int index1,int index2,vector<vector<int>> & dp){
        if(index1<0) return index2+1;
        if(index2<0) return index1+1;
        if(dp[index1][index2]!=-1) return dp[index1][index2];
        if(word1[index1]==word2[index2]){
            return dp[index1][index2]= solve(word1,word2,index1-1,index2-1,dp);
        }
        int first=1+solve(word1,word2,index1,index2-1,dp); //insert
        int second=1+solve(word1,word2,index1-1,index2,dp); //delete
        int third=1+solve(word1,word2,index1-1,index2-1,dp); //replace
        return dp[index1][index2]= min(first,min(second,third));
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return solve(word1,word2,word1.size()-1,word2.size()-1,dp);
    }
};
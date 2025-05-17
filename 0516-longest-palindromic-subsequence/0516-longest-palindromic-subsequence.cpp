class Solution {
public:
    int solve(string &first,string &second,int index1,int index2,vector<vector<int>> & dp){
        if(index1<0 || index2<0) return 0;
        if(dp[index1][index2]!=-1) return dp[index1][index2];
        if(first[index1]==second[index2]){
            return dp[index1][index2]= 1+solve(first,second,index1-1,index2-1,dp);
        }
        return dp[index1][index2]= max(solve(first,second,index1-1,index2,dp),solve(first,second,index1,index2-1,dp));
    }
    int longestPalindromeSubseq(string s) {
        string temp=s;
        reverse(s.begin(),s.end());
        int n=s.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return solve(temp,s,s.size()-1,s.size()-1,dp);
    }
};
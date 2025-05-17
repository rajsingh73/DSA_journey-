class Solution {
public:
    int solve(string &first,string &second,int index1,int index2,vector<vector<int>> &dp){
        if(index1<0 || index2<0) return 0;
        if(dp[index1][index2]!=-1) return dp[index1][index2];
        if(first[index1]==second[index2]) return dp[index1][index2]=1+solve(first,second,index1-1,index2-1,dp);
        return dp[index1][index2]=max(solve(first,second,index1-1,index2,dp),solve(first,second,index1,index2-1,dp));
    }
    int minInsertions(string s) {
        string temp=s;
        int n=s.size();
        reverse(s.begin(),s.end());
        vector<vector<int>> dp(n,vector<int> (n,-1));
        int ans=solve(s,temp,n-1,n-1,dp);
        return n-ans;
    }
};
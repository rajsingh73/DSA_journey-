class Solution {
public:
    int solve(string &s,string &t,int index1,int index2,vector<vector<int>> & dp){
        if(index2<0) return 1;
        if(index1<0) return 0;
        if(dp[index1][index2]!=-1) return dp[index1][index2];
        int first=0;
        if(s[index1]==t[index2]){
            first=solve(s,t,index1-1,index2-1,dp);
        }
        first+=solve(s,t,index1-1,index2,dp);
        return dp[index1][index2]= first;
    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return solve(s,t,s.size()-1,t.size()-1,dp);
    }
};
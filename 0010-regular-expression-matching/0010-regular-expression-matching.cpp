class Solution {
public:
    bool solve(string &s,string &p,int first,int second,vector<vector<int>> &dp){
        if(first<0 && second<0) return true;
        if(second<0) return false;
        if(first<0){
            if(p[second]=='*') return solve(s,p,first,second-2,dp);
            else return false;
        }
        if(dp[first][second]!=-1) return dp[first][second];
        if(p[second]=='*'){
            bool notake=solve(s,p,first,second-2,dp);
            bool take=(s[first]==p[second-1] || p[second-1]=='.') && solve(s,p,first-1,second,dp);
            return dp[first][second]= take || notake;
        }
        if(p[second]=='.' || p[second]==s[first]){
            return dp[first][second]=solve(s,p,first-1,second-1,dp);
        }
        return dp[first][second]= false;
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=s.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(s,p,n-1,m-1,dp);
        
    }
};
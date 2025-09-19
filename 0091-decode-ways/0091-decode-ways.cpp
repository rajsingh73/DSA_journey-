class Solution {
public:
    int solve(string &s,vector<vector<int>> & dp,int index,int prev,int val){
        if(index==s.size()){
            return 1;
        }
        if(dp[index][prev]!=-1) return dp[index][prev];
        if(prev){
            if(val==0 || val>2) return dp[index][prev]= 0;
            if(s[index]-'0'>6 && val==2) return dp[index][prev]=  0;
            return dp[index][prev]=solve(s,dp,index+1,0,0);
        }
        else {
            if(s[index]-'0'==0) return dp[index][prev]=0;
            if(index==s.size()-1) return dp[index][prev]= 1;
            return dp[index][prev] = solve(s,dp,index+1,0,val)+solve(s,dp,index+1,1,s[index]-'0');
        }
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        int val=s[0]-'0';
        cout<<val;
        return solve(s,dp,0,0,0);
    }
};
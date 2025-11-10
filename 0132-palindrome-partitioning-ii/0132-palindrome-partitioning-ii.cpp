class Solution {
public:
    bool palindorm(int start,int end,string &s){
        while(start<end){
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }
        if(start==end || start>end) return true;
        return false;
    }
    int solve(string & s,int start,vector<int> &dp){
        if(start==s.size()) return 0;
        int ans=INT_MAX;
        if(dp[start]!=-1) return dp[start];
        for(int i=start;i<s.size();i++){
            if(palindorm(start,i,s)){
                int way=1+solve(s,i+1,dp);
                ans=min(ans,way);
            }
        }
        return dp[start]= ans;
    }
    int minCut(string s) {
        int n=s.size();
        vector<int> dp(n,-1);
        return solve(s,0,dp)-1;
        
    }
};
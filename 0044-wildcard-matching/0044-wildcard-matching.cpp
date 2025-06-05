class Solution {
public:
    int solve(string &s,string &p,int index1,int index2,vector<vector<int>> &dp){
        if(index1==-1 && index2==-1) return true;
        if(index1==-1){
            for(int i=index2;i>=0;i--){
                if(p[i]!='*') return false;
            }
            return true;
        }
        if(index2==-1) return false;
        if(dp[index1][index2]!=-1) return dp[index1][index2];
        if(p[index2]=='?' || p[index2]==s[index1]){
            return dp[index1][index2]= solve(s,p,index1-1,index2-1,dp);
        }
        if(p[index2]=='*'){
            return dp[index1][index2]= solve(s,p,index1,index2-1,dp) || solve(s,p,index1-1,index2,dp);
        } 
        return dp[index1][index2] =false;
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(s,p,n-1,m-1,dp);
        
    }
};
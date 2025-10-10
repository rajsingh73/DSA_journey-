class Solution {
public:
    bool solve(string &s1,string &s2,string &s3,int i,int j,int val,int n,int m,vector<vector<int>> & dp){
        if(val==s3.size()) {
            if((i>0 && j==0 && m>0) || (i==0 && j>0 && n>0)) return false;
            return true;
        };
        if(dp[i][j]!=-1) return dp[i][j];
        if(i<n && j<m && s1[i]==s3[val] && s2[j]==s3[val]){
            return dp[i][j]= solve(s1,s2,s3,i+1,j,val+1,n,m,dp) || solve(s1,s2,s3,i,j+1,val+1,n,m,dp);
        }
        else if(i<n && s3[val]==s1[i]) return dp[i][j]= solve(s1,s2,s3,i+1,j,val+1,n,m,dp);
        else if(j<m && s3[val]==s2[j]) return dp[i][j]= solve(s1,s2,s3,i,j+1,val+1,n,m,dp);
        return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;
        if(s3.size()==0 && (s1.size()>0 || s2.size()>0)) return false;
        vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        return solve(s1,s2,s3,0,0,0,s1.size(),s2.size(),dp);
    }
};
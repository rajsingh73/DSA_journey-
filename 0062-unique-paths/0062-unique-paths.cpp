class Solution {
public:
    int solve(int n,int m,vector<vector<int>> & dp){
        if(n==0 && m==0) return 1;
        if(n<0 || m<0) return 0;
        if(dp[n][m]!=0) return dp[n][m];
        int up=solve(n-1,m,dp);
        int left=solve(n,m-1,dp);
        return dp[n][m]=up+left;
    }
    int uniquePaths(int m, int n) {
        vector<int> v(n,0);
        for(int i=0;i<m;i++){
            vector<int> temp(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0) temp[0]=1;
                else{
                    int up=0;
                    int down=0;
                    if(i>0) up+=v[j];
                    if(j>0) down+=temp[j-1];
                    temp[j]=up+down;
                }
            }
            v=temp;
        }
        return v[n-1];
        
    }
};
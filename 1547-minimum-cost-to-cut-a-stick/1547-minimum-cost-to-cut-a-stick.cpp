class Solution {
public:
    int minCost(int n, vector<int>& v) {
        v.insert(v.begin(),0);
        v.push_back(n);
        int m=v.size();
        vector<vector<int>> dp(m,vector<int>(m));
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                if(i>j) dp[i][j]=0;
            }
        }
        sort(v.begin(),v.end());
        for(int start=m-2;start>=1;start--){
            for(int end=1;end<=m-2;end++){
                if(start<=end){
                    int ans=INT_MAX;
                    for(int index=start;index<=end;index++){
                        int step= v[end+1]-v[start-1] +dp[start][index-1] + dp[index+1][end];
                        ans=min(ans,step);
                    }
                    dp[start][end]= ans;
                }
            }
        }
        return dp[1][m-2];
        
    }
};
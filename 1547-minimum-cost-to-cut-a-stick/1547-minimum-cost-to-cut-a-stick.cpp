class Solution {
public:
    int solve(vector<int> & cuts,int start, int end,vector<vector<int>> & dp){
        if(start>end) return 0;
        int ans=INT_MAX;
        if(dp[start][end]!=-1) return dp[start][end];
        for(int index=start;index<=end;index++){
            int step=cuts[end+1]-cuts[start-1]+solve(cuts,start,index-1,dp)+solve(cuts,index+1,end,dp);
            ans=min(ans,step);
        }
        return dp[start][end]= ans;
    }
    int minCost(int n, vector<int>& v) {
        v.insert(v.begin(),0);
        v.push_back(n);
        int m=v.size();
        vector<vector<int>> dp(m,vector<int>(m,-1));
        sort(v.begin(),v.end());
        return solve(v,1,v.size()-2,dp);
        
    }
};
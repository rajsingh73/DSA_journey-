class Solution {
public:
    int solve(vector<int>&prices,int fee,int index,vector<vector<int>> & dp,int buy){
        if(index==prices.size()) return 0;
        if(dp[index][buy]!=-1) return dp[index][buy];
        if(buy){
            return dp[index][buy]=max(-prices[index]+solve(prices,fee,index+1,dp,0),solve(prices,fee,index+1,dp,1));
        }
        return dp[index][buy]=max(prices[index]+solve(prices,fee,index+1,dp,1)-fee,solve(prices,fee,index+1,dp,0));
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return solve(prices,fee,0,dp,1);
        
    }
};
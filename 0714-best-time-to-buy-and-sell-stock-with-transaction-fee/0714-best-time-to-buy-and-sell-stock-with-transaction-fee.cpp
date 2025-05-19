class Solution {
public:
    int solve(vector<int> & prices,int index,int buy,int fee,vector<vector<int>> &dp){
        if(index==prices.size()) return 0;
        if(dp[index][buy]!=-1) return dp[index][buy];
        if(buy){
            return dp[index][buy]= max(-prices[index]+solve(prices,index+1,0,fee,dp),solve(prices,index+1,1,fee,dp));
        }
        else{
            return dp[index][buy]= max(prices[index]+solve(prices,index+1,1,fee,dp)-fee,solve(prices,index+1,0,fee,dp));
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int> (2,-1));
        return solve(prices,0,1,fee,dp);
        
    }
};
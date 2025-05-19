class Solution {
public:
    int solve(vector<int> & prices,int index,int buy,vector<vector<int>> & dp){
        if(index>prices.size()-1) return 0;
        if(dp[index][buy]!=-1) return dp[index][buy];
        if(buy){
            return dp[index][buy]= max(-prices[index]+solve(prices,index+1,0,dp),solve(prices,index+1,1,dp));
        }
        else{
            return dp[index][buy]= max(prices[index]+solve(prices,index+2,1,dp),solve(prices,index+1,0,dp));
        }

    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(prices,0,1,dp);

        
    }
};
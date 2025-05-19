class Solution {
public:
    int solve(vector<int> & prices,int index,int buy,int cap,vector<vector<vector<int>>> & dp){
        if(cap==0) return 0;
        if(index==prices.size()) return 0;
        if(dp[index][buy][cap]!=-1) return dp[index][buy][cap];
        if(buy){
            return dp[index][buy][cap]= max(-prices[index]+solve(prices,index+1,0,cap,dp),solve(prices,index+1,1,cap,dp));
        }
        else{
            return dp[index][buy][cap]= max(prices[index]+solve(prices,index+1,1,cap-1,dp),solve(prices,index+1,0,cap,dp));
        }

    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int>(3,-1)));
        return solve(prices,0,1,2,dp); 
    }
};
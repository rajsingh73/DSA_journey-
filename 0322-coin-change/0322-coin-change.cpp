class Solution {
public:
    int solve(vector<int>& coins,int index,int amount,vector<vector<int>> & dp){
        if(index==0){
            if(amount%coins[index]==0) return amount/coins[index];
            return 1e9;
        }
        if(dp[index][amount]!=-1) return dp[index][amount];
        int nottake=0+solve(coins,index-1,amount,dp);
        int take=1e9;
        if(amount>=coins[index]){
            take=1+solve(coins,index,amount-coins[index],dp);
        }
        return dp[index][amount]= min(nottake,take);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int ans =solve(coins,coins.size()-1,amount,dp);
        if(ans==1e9) return -1;
        return ans;
        
    }
};
class Solution {
public:
    int solve(vector<int> & coins,int amount,int index){
        if(amount==0) return 1;
        if(index==0){
            if(amount%coins[index]==0) return 1;
            else return 0;
        }
        int notpick=solve(coins,amount,index-1);
        int pick=0;
        if(amount>=coins[index]) pick=solve(coins,amount-coins[index],index);
        return pick+notpick;
    }
    int change(int amount, vector<int>& coins) {
        if(amount==0) return 1;

        return solve(coins,amount,coins.size()-1);
    }
};
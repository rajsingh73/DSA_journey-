class Solution {
public:
    int solve(vector<int> &nums,int index,int prev,vector<vector<int>> &dp){
        if(index==nums.size()) return 0;
        if(dp[index][prev+1]!=-1) return dp[index][prev+1];
        int len=solve(nums,index+1,prev,dp);
        if(prev==-1 || nums[index]>nums[prev]){
            len=max(len,1+solve(nums,index+1,index,dp));
        }
        return dp[index][prev+1]= len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(nums,0,-1,dp);
        
    }
};
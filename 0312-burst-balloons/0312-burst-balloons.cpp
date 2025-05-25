class Solution {
public:
    int solve(vector<int> &nums,int start,int end,vector<vector<int>> & dp){
        if(start>end) return 0;
        int ans=INT_MIN;
        if(dp[start][end]!=-1) return dp[start][end];
        for(int i=start;i<=end;i++){
            int step=nums[start-1]*nums[i]*nums[end+1] + solve(nums,start,i-1,dp) + solve(nums,i+1,end,dp);
            ans=max(ans,step);
        }
        return dp[start][end]= ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(nums,1,n-2,dp);
    }
};
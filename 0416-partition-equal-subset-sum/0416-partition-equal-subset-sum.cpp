class Solution {
public:
    bool solve(vector<int> & nums,int target,int sub,int index,vector<vector<int>> & dp){
        if(target==sub) return true;
        if(index==nums.size()-1) return sub+nums[index]==target;
        if(target<sub) return false;
        if(dp[index][sub]!=-1) return dp[index][sub];
        bool nottake=solve(nums,target,sub,index+1,dp);
        bool take=false;
        if(sub+nums[index]<=target) take=solve(nums,target,sub+nums[index],index+1,dp);
        return dp[index][sub]=nottake | take;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i:nums) sum+=i;
        if(sum%2!=0) return false;
        int target=sum/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return solve(nums,target,0,0,dp);
        
    }
};
class Solution {
public:
    int rob(vector<int>& nums) {
        int dp[nums.size()+1];
        dp[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            int take=nums[i];
            if(i>1){
                take=take+dp[i-2];
            }
            int nottake=dp[i-1];
            dp[i]=max(take,nottake);
        }
        return dp[nums.size()-1];
    }
};
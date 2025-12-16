class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> dp(nums.size()+1,0);
        for(int i=0;i<nums.size();i++) dp[nums[i]]++;
        int missing=0;
        int dup=0;
        for(int i=1;i<dp.size();i++){
            if(dp[i]==0) missing=i;
            if(dp[i]==2) dup=i;
        }
        return {dup,missing};
    }
};
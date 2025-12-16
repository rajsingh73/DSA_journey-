class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> dp(nums.size()+1,0);
        vector<int> ans;
        for(int i=0;i<nums.size();i++) dp[nums[i]]++;
        for(int i=1;i<dp.size();i++){
            if(dp[i]==0) ans.push_back(i);
        }
        return ans;
    }
};
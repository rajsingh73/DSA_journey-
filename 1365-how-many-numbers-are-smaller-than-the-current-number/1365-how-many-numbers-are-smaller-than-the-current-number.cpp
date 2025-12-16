class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<pair<int,int>> dp;
        int n=nums.size();
        for(int i=0;i<nums.size();i++) dp.push_back({nums[i],i});
        sort(dp.begin(),dp.end());
        int count=0;
        int prev=-1;
        vector<int> ans(nums.size());
        int i=0;
        while(i<n){
            int temp=0;
            int val=dp[i].first;
            while(i<n && dp[i].first==val){
                int index=dp[i].second;
                ans[index]=count;
                i++;
                temp++;
            }
            count+=temp;
        }
        return ans;
    }
};
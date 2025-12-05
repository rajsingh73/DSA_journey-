class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum=0;
        for(auto it: nums)sum+=it;
        int prefixsum=nums[0];
        int ans=0;
        for(int i=1;i<nums.size();i++){
            int rem=sum-prefixsum;
            if((rem-prefixsum)%2==0) ans++;
            prefixsum+=nums[i];
        }
        return ans;
    }
};
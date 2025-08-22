class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first=nums[0];
        int second=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>first && second>nums[i]) second=nums[i];
            else if(nums[i]>second) return true;
            first=min(first,nums[i]);
        }
        return false;
        
    }
};
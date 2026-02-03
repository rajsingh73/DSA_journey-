class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        if(nums[0]>=nums[1]) return false;
        int i=1;
        int n=nums.size();
        while(i<n && nums[i-1]<nums[i]) i++;
        if(i>=n-1) return false;
        while(i<n && nums[i-1]>nums[i]) i++;                                    
        if(i>=n) return false;
        while(i<n && nums[i-1]<nums[i]) i++;
        return i==n;
    }
};
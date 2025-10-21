class Solution {
public:
    bool check(vector<int>& nums) {
        if(nums.size()<2) return true;
        int val=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]) val++;
        }
        if(nums[nums.size()-1]>nums[0]) val++;
        if(val>1) return false;
        return true;;
        
    }
};
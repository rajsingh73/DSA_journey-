class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int yes=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1) yes=1;
            if(nums[i]<=0) nums[i]=1;
            if(nums[i]>nums.size()) nums[i]=1;
        }
        if(yes==0) return 1;
        for(int i=0;i<nums.size();i++){
            int value=abs(nums[i]);
            value=value-1;
            if(nums[value]>0) nums[value]=nums[value]*-1;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0) return i+1;
        }
        return nums.size()+1;
        
    }
};
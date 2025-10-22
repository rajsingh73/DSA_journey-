class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int low=0;
        int i=0;
        while(i<nums.size()){
            nums[low]=nums[i];
            i++;
            while(i<nums.size() && nums[low]==nums[i]) i++;
            low++;
        }
        return low;
        
    }
};
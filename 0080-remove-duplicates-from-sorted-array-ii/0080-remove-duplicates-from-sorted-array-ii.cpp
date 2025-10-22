class Solution {
public:
    int removeDuplicates(vector<int>& nums){
        int low=0;
        int i=0;
        while(i<nums.size()){
            nums[low]=nums[i];
            i++;
            if(i<nums.size() && nums[low]==nums[i]){
                low++;
                nums[low]=nums[i];
            }
            while(i<nums.size() && nums[low]==nums[i]) i++;
            low++;
        }
        return low;
    }
};
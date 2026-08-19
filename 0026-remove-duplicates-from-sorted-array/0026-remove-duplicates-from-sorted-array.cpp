class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int j=0;
        while(i<nums.size()){
            nums[j]=nums[i];
            j++;
            i++;
            while(i<nums.size() && nums[i]==nums[i-1]) i++;
        }
        return j;
        
    }
};
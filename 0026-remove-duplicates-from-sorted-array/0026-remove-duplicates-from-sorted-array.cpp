class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count=0;
        int i=0;
        while(i<nums.size()){
            nums[count++]=nums[i++];
            while(i<nums.size() && nums[i]==nums[i-1]) i++;
        }
        return count;
    }
};
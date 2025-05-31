class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int past=nums[0];
        int j=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=past){
                past=nums[i];
                nums[j]=nums[i];
                j++;
            }
        }
        return j;
    }
};
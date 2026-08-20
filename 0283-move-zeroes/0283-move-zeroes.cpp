class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0) {
                nums[j]=nums[i];
                j++;
            }
            if(j-1!=i)nums[i]=0;
        }
        
    }
};
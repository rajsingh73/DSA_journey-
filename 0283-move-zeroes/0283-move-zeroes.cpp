class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index=0;
        int a=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) a++;
            else{
                nums[index]=nums[i];
                index++;
            }
        }
        for(int i=0;i<a;i++){
            nums[index]=0;
            index++;
        }
    }
};
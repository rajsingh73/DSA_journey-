class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        while(i<j){
            while(i<j && nums[i]%2==0)i++;
            while(j>i && nums[j]%2==1)j--;
            if(i<j) {
                swap(nums[i],nums[j]);
                j--;
                i++;
            }
        }
        return nums;
        
    }
};
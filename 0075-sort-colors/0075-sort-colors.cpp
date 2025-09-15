class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int zerocount=0;
        int twocount=n-1;
        int start=0;
        while(start<=twocount){
            if(nums[start]==0){
                swap(nums[start],nums[zerocount]);
                start++;
                zerocount++;
            }
            else if(nums[start]==2){
                swap(nums[start],nums[twocount]);
                twocount--;
            }
            else start++;
        }
        
    }
};
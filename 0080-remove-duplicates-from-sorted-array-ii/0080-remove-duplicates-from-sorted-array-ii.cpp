class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int start=0;
        while(i<nums.size()){
            int val=nums[i];
            int count=0;
            while(i<nums.size() && val==nums[i]){
                if(count<2){
                    nums[start]=nums[i];
                    count++;
                    start++;
                }
                i++;
            }
        }
        return start;
        
    }
};
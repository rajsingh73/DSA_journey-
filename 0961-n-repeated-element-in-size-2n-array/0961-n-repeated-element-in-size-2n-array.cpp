class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int val=-1;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(val==nums[i]) return val;
            else if(count==0){
                val=nums[i];
                count=1;
            }
            else count--;
        }
        return val;  
    }
};
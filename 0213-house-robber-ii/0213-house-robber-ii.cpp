class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int prev1=nums[0];
        int prev2=0;
        for(int i=1;i<nums.size()-1;i++){
            int take=nums[i]+prev2;
            int notake=prev1;
            prev2=prev1;
            prev1=max(take,notake);
        }
        int temp=prev1;
        if(nums.size()>1){
            prev1=nums[1];
            prev2=0;
            for(int i=2;i<nums.size();i++){
                int take=nums[i]+prev2;
                int notake=prev1;
                prev2=prev1;
                prev1=max(take,notake);
            }
        }
        return max(temp,prev1);
        
    }
};
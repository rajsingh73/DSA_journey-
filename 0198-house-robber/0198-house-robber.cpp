class Solution {
public:
    int rob(vector<int>& nums){
        int prev=0;
        int prev2=0;
        for(int i=0;i<nums.size();i++){
            int take=nums[i];
            if(i>1){
                take+=prev2;
            }
            int nottake=prev;
            int curr=max(take,nottake);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};
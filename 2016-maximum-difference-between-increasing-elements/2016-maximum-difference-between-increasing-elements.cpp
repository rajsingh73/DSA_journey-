class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int low=nums[0];
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            if(low<nums[i]){
                ans=max(ans,nums[i]-low);
            }
            low=min(low,nums[i]);
        }
        return ans;
        
    }
};
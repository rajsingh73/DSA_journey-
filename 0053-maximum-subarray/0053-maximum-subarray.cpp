class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            if(sum<0){
                ans=max(ans,nums[i]);
                sum=0;
            }
            else ans=max(ans,sum);
        }
        return ans;
        
    }
};
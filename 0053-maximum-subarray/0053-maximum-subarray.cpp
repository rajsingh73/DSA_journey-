class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int ans=INT_MIN;
        for(auto it: nums){
            sum+=it;
            if(sum<0){
                ans=max(ans,sum);
                sum=0;
            }
            else ans=max(ans,sum);
        }
        return ans;
    }
};
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> c(n,1);
        int longest=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){      
                if(nums[i]>nums[j] && 1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                    c[i]=c[j];
                }
                else if(nums[i]>nums[j] && 1+dp[j]==dp[i]){
                    c[i]+=c[j];
                }
            }
            longest=max(longest,dp[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(dp[i]==longest) ans+=c[i];
        }
        return ans;
        
    }
};
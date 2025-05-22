class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);
        vector<int> hash(n);
        int maxi=0;
        sort(nums.size(),nums.begin());
        int longest=0;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && 1+dp[j]>dp[i]){
                    hash[i]=j;
                    dp[i]=1+dp[j];
                }
                if(maxi<dp[i]){
                    maxi=dp[i];
                    longest=i;
                }

            }
        }
        vector<int> ans;
        while(hash[longest]!=longest){
            ans.push_back(nums[longest]);
            longest=hash[longest];
        }
        ans.push_back(nums[longest]);
        return  ans;

        
    }
};
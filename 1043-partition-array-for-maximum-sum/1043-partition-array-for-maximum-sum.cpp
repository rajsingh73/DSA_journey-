class Solution {
public:
    int solve(vector<int> & arr,int start,int k,vector<int> &dp){
        if(start==arr.size()) return 0;
        int maxi=0;
        int ans=INT_MIN;
        if(dp[start]!=-1) return dp[start];
        int n=arr.size();
        int value=min(start+k,n);
        for(int i=start;i<value;i++){
            maxi=max(maxi,arr[i]);
            int way=maxi*(i-start+1)+solve(arr,i+1,k,dp);
            ans=max(ans,way);
        }
        return dp[start]= ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n,-1);
        return solve(arr,0,k,dp);
    }
};
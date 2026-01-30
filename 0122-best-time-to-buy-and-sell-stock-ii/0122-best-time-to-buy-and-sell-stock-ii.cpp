class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int n=prices.size();
        int maxi=prices[n-1];
        for(int i=n-2;i>=0;i--){
            if(maxi>prices[i]){
                ans+=(maxi-prices[i]);
                maxi=prices[i];
            }
            else maxi=max(maxi,prices[i]);
        }
        return ans;
    }
};
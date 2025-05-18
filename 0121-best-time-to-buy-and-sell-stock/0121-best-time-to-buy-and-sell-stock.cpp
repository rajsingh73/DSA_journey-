class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int val=1e5;
        for(int i=0;i<prices.size();i++){
            val=min(val,prices[i]);
            ans=max(ans,prices[i]-val);
        }
        return ans;
    }
};
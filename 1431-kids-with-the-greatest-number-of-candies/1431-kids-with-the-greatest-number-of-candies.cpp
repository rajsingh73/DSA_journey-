class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi=0;
        for(auto it: candies) maxi=max(maxi,it);
        vector<bool> ans;
        for(auto it:candies){
            if(it+extraCandies<maxi) ans.push_back(false);
            else ans.push_back(true);
        }
        return ans;
        
    }
};
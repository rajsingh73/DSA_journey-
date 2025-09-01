class Solution {
public:
    int solve(int val,vector<int> & potions,long long success ){
        int low=0;
        int high=potions.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long temp=long long(potions[mid]*val);
            if(temp>=success) high=mid-1;
            else low=mid+1;
        }
        return potions.size()-low;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int> ans;
        for(int i=0;i<spells.size();i++){
            int val=solve(spells[i],potions,success);
            ans.push_back(val);
        }
        return ans;

    }
};
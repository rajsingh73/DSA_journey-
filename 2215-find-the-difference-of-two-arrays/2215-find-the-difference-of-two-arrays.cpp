class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp;
        vector<int> first;
        vector<int> second;
        for(auto it: nums1) mp[it]=1;
        for(auto it: nums2){
            if(mp.find(it)==mp.end()) {
                second.push_back(it);
                mp[it]=2;
            }
            else mp[it]=2;
        }
        for(auto it: mp){
            if(it.second==1) first.push_back(it.first);
        }
        return {first,second};
    }
};
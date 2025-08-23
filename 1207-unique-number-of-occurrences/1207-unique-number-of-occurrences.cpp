class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> mp;
        for(auto it: arr) mp[it]++;
        map<int,int> temp;
        for(auto it: mp) temp[it.second]++;
        for(auto it: temp){
            if(it.second>1) return false;
        }
        return true;
        
    }
};
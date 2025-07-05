class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int> mp;
        for(int it:arr) mp[it]++;
        int ans=-1;
        for(auto it : mp){
            if(it.first==it.second) ans=max(ans,it.first);
        }
        return ans;
        
    }
};
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        map<vector<int>,int> mp;
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int> temp;
            for(int j=0;j<n;j++){
                temp.push_back(grid[j][i]);
            }
            mp[temp]++;
        }
        for(int i=0;i<n;i++){
            if(mp.find(grid[i])!=mp.end()) ans+=mp[grid[i]];
        }
        return ans;
    }
};
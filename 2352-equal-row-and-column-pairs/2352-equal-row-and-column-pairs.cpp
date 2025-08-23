class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        map<string,int> mp;
        int ans=0;
        for(int i=0;i<n;i++){
            string temp="";
            for(int j=0;j<n;j++){
                temp+=to_string(grid[j][i])+",";
            }
            mp[temp]++;
        }
        for(int i=0;i<n;i++){
            string temp="";
            for(int j=0;j<n;j++){
                temp+=to_string(grid[i][j])+",";
            }
            if(mp.count(temp)) ans+=mp[temp];
        }
        return ans;

        
    }
};
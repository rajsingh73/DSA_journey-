class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<pair<char,int>> row(n,{'s',0});
        vector<pair<char,int>> col(n,{'s',0});
        vector<vector<int>> ans(n,vector<int>(n,0));
        for(auto it: queries){
            for(int i=it[0];i<=it[2];i++){
                for(int j=it[1];j<=it[3];j++){
                    ans[i][j]++;
                }
            }
        }
        return ans;
    }
};
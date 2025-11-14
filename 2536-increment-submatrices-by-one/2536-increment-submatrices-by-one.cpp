class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diff(n+1,vector<int>(n+1,0));
        vector<vector<int>> ans(n,vector<int>(n,0));
        for(auto it: queries){
            int row1=it[0],col1=it[1],row2=it[2],col2=it[3];
            diff[row1][col1]++;
            diff[row1][col2+1]--;
            diff[row2+1][col1]--;
            diff[row2+1][col2+1]++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i>0) diff[i][j]+=diff[i-1][j];
                if(j>0) diff[i][j]+=diff[i][j-1];
                if(i>0 && j>0) diff[i][j]-=diff[i-1][j-1];
                ans[i][j]=diff[i][j];
            }
        }
        return ans;
    }
};
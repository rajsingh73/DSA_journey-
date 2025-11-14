class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<pair<char,int>> row(n,{'s',0});
        vector<pair<char,int>> col(n,{'s',0});
        vector<vector<int>> ans(n,vector<int>(n,0));
        vector<vector<int>> diff(n,vector<int>(n,0));
        for(auto it: queries){
            int row1=it[0],col1=it[1],row2=it[2],col2=it[3];
            for(int i=row1;i<=row2;i++){
                diff[i][col1]+=1;
                if(col2+1<n) diff[i][col2+1]-=1;
            }
        }
        for(int i=0;i<n;i++){
            int pre=0;
            for(int j=0;j<n;j++){
                pre+=diff[i][j];
                ans[i][j]=pre;
            }
        }
        return ans;
    }
};
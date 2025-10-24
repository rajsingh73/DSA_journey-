class Solution {
public:
    int solve(int val){
        int ans=0;
        if(val<=0) {
            ans++;
            val=val*-1;
        }
        while(val>0){
            val=val/10;
            ans++;
        }
        return ans;
    }
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<int> ans(col);
        for(int i=0;i<col;i++){
            int maxi=0;
            for(int j=0;j<row;j++){
                maxi=max(maxi,solve(grid[j][i]));
            }
            ans[i]=maxi;
        }
        return ans;
    }
};
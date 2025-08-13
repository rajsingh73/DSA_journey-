class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int newrow=x+k-1;
        int newcol=y+k-1;
        while(x<newrow){
            for(int i=y;i<=newcol;i++){
                int val=grid[x][i];
                grid[x][i]=grid[newrow][i];
                grid[newrow][i]=val;
            }
            x++;
            newrow--;
        }
        return grid;
    }
};
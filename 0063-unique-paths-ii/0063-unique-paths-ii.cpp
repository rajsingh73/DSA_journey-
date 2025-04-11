class Solution {
public:
    int solve(vector<vector<int>> & obstacleGrid,int n,int m){
        if(n<0 || m<0)  return 0;
        if(obstacleGrid[n][m]==1) return 0;
        if(n==0 && m==0) return 1;
        int up=solve(obstacleGrid,n-1,m);
        int down=solve(obstacleGrid,n,m-1);
        return up+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        return solve(obstacleGrid,n-1,m-1);
    }
};
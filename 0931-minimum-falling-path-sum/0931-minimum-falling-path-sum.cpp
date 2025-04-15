class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int mini = INT_MAX;
        for(int i=0;i<matrix[0].size();i++){
            dp[0][i]=matrix[0][i];
        }
        for(int i=1;i<matrix.size();i++){
            for(int j=0;j<matrix.size();j++){
                int top=matrix[i][j]+dp[i-1][j];
                int left=1e9;
                int right=1e9;
                if(j>0) left=matrix[i][j]+dp[i-1][j-1];
                if(j<matrix.size()-1) right=matrix[i][j]+dp[i-1][j+1];
                dp[i][j]=min(top,min(left,right));
            }
        }
        for(int i=0;i<matrix.size();i++){
            mini=min(mini,dp[matrix.size()-1][i]);
        }
        return mini;
    }
};

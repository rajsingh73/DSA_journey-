class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int i=0;
        int j=m-1;
        while(true){
            cout<<"HELLo i am enter";
            if(i<0 || j<0 || j>=m || i>=n) return false;
            cout<<matrix[i][j]<<" ";
            if(matrix[i][j]==target) return true;
            if(matrix[i][j]>target)j=j-1;
            else i=i+1;
        }
        return false;
    }
};
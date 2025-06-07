class Solution {
public:
    void dfs(vector<vector<int>> & image,int row,int col,int color,int n,int m,int initial){
        if(row<0 || row>=n || col<0 || col>=m || image[row][col]!=initial) return;
        image[row][col]=color;
        dfs(image,row+1,col,color,n,m,initial);
        dfs(image,row,col+1,color,n,m,initial);
        dfs(image,row-1,col,color,n,m,initial);
        dfs(image,row,col-1,color,n,m,initial);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        if(image[sr][sc]==color) return image;
        int initial=image[sr][sc];
        dfs(image,sr,sc,color,n,m,initial);
        return image;
    }
};
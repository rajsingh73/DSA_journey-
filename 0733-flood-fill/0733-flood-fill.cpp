class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> visited(n,vector<int>(m,0));
        if(image[sr][sc]==color) return image;
        q.push({image[sr][sc],{sr,sc}});
        visited[sr][sc]=1;
        image[sr][sc]=color;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                pair<int,pair<int,int>> p=q.front();
                q.pop();
                int initial=p.first;
                int row=p.second.first;
                int col=p.second.second;
                int nrow=row+1;
                int ncol=col;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==initial && visited[nrow][ncol]==0){
                    q.push({image[nrow][ncol],{nrow,ncol}});
                    visited[nrow][ncol]=1;
                    image[nrow][ncol]=color;
                }
                nrow=row;
                ncol=col+1;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==initial && visited[nrow][ncol]==0){
                    q.push({image[nrow][ncol],{nrow,ncol}});
                    visited[nrow][ncol]=1;
                    image[nrow][ncol]=color;
                }
                nrow=row-1;
                ncol=col;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==initial && visited[nrow][ncol]==0){
                    q.push({image[nrow][ncol],{nrow,ncol}});
                    visited[nrow][ncol]=1;
                    image[nrow][ncol]=color;
                }
                nrow=row;
                ncol=col-1;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==initial && visited[nrow][ncol]==0){
                    q.push({image[nrow][ncol],{nrow,ncol}});
                    visited[nrow][ncol]=1;
                    image[nrow][ncol]=color;
                }
            }
        }
        return image;
    }
};
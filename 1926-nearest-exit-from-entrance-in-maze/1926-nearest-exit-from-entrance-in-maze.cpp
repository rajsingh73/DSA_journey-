class Solution {
public:
    bool isvalid(int row,int col,int n,int m,vector<vector<int>> visited,vector<vector<char>> maze){
        return (row>=0 && row<n && col>=0 && col<m) && visited[row][col]==0 && maze[row][col]=='.';
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int,int>> q;
        q.push({entrance[0],entrance[1]});
        int n=maze.size();
        int m=maze[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        visited[entrance[0]][entrance[1]]=1;
        int res=0;
        int first=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto p=q.front(); q.pop();
                int row=p.first;
                int col=p.second;
                if((row==0 || col==0 || row==n-1 || col==m-1) && first==1 ) return res;
                int nrow=row+1;
                int ncol=col;
                if(isvalid(nrow,ncol,n,m,visited,maze)){
                    q.push({nrow,ncol});
                    visited[nrow][ncol]=1;
                }
                nrow=row-1;
                ncol=col;
                if(isvalid(nrow,ncol,n,m,visited,maze)){
                    q.push({nrow,ncol});
                    visited[nrow][ncol]=1;
                }
                nrow=row;
                ncol=col+1;
                if(isvalid(nrow,ncol,n,m,visited,maze)){
                    q.push({nrow,ncol});
                    visited[nrow][ncol]=1;
                }
                nrow=row;
                ncol=col-1;
                if(isvalid(nrow,ncol,n,m,visited,maze)){
                    q.push({nrow,ncol});
                    visited[nrow][ncol]=1;
                }
            }
            first=1;
            res++;

        }
        return -1;
        
    }
};
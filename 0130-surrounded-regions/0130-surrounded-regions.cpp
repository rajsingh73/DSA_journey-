class Solution {
public:
    void dfs(vector<vector<char>> & board,int row,int col,vector<vector<int>> & visited,int n,int m){
        if(row<0 || row>=n || col<0 || col>=m || visited[row][col]==1 || board[row][col]=='X') return;
        visited[row][col]=1;
        dfs(board,row+1,col,visited,n,m);
        dfs(board,row,col+1,visited,n,m);
        dfs(board,row-1,col,visited,n,m);
        dfs(board,row,col-1,visited,n,m);
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(board[i][0]=='O') dfs(board,i,0,visited,n,m);
            if(board[i][m-1]=='O') dfs(board,i,m-1,visited,n,m);
        }
        for(int i=0;i<m;i++){
            if(board[0][i]=='O') dfs(board,0,i,visited,n,m);
            if(board[n-1][i]=='O') dfs(board,n-1,i,visited,n,m);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0) board[i][j]='X';
            }
        }
    }
};
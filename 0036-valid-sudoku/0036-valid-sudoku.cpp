class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]!='.'){
                    if(!isvalid(board,i,j)) return false;
                }
            }
        }
        return true;   
    }
    bool isvalid(vector<vector<char>> & board,int row,int col){
        for(int i=0;i<9;i++){
            if(i!=col) if(board[row][i]==board[row][col]) return false;
            if(i!=row) if(board[i][col]==board[row][col]) return false;
            int newrow=(3*(row/3)+i/3);
            int newcol=(3*(col/3)+i%3);
            if(newrow!=row || newcol!=col){
                if(board[newrow][newcol]==board[row][col]) return false;
            }
        }
        return true;
    }
};
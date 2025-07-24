class Solution {
public:
    bool check(vector<string> v,int col,int row,int n){
        for(int i=row;i>=0;i--){
            if(v[i][col]=='Q') return false;
        }
        for(int i=col;i>=0;i--){
            if(v[row][i]=='Q') return false;
        }
        int roww=row;
        int coll=col;
        while(roww>=0 && coll>=0){
            if(v[roww][coll]=='Q') return false;
            roww--;
            coll--;
        }
        roww=row;
        coll=col;
        while(roww<n && coll>=0){
            if(v[roww][coll]=='Q') return false;
            roww++;
            coll--;
        }
        return true;
    }
    void solve(int col,int n,vector<vector<string>> & ans,vector<string> v){
        if(col==n){
            ans.push_back(v);
        }
        for(int i=0;i<n;i++){
            if(check(v,col,i,n)){
                v[i][col]='Q';
                solve(col+1,n,ans,v);
                v[i][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> v;
        string s="";
        for(int i=0;i<n;i++) s+=".";
        for(int i=0;i<n;i++) v.push_back(s);
        solve(0,n,ans,v);
        return ans;
    }
};
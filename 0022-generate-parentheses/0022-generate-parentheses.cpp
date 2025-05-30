class Solution {
public:
    void solve(int open,int close,vector<string> & ans,string s ){
        if(open==0 && close==0){
            ans.push_back(s);
            return;
        }
        if(open==close){
            s.push_back('(');
            solve(open-1,close,ans,s);
            return;
        }
        if(open==0){
            s.push_back(')');
            solve(open,close-1,ans,s);
            return;
        }
        else{
            s.push_back('(');
            solve(open-1,close,ans,s);
            s.pop_back();
            s.push_back(')');
            solve(open,close-1,ans,s);
            return;
        }

    }
    vector<string> generateParenthesis(int n) {
        string s="";
        vector<string> ans;
        int open=n;
        int close=n;
        solve(open,close,ans,s);
        return ans;
        
    }
};
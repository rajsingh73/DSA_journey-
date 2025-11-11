class Solution {
public:
    void solve(int open,int close,string temp,vector<string> & ans){
        if(open==0 && close==0){
            ans.push_back(temp);
            return;
        }
        if(open==0){
            temp.push_back(')');
            solve(open,close-1,temp,ans);
        }
        else if(open==close){
            temp.push_back('(');
            solve(open-1,close,temp,ans);
        }
        else{
            temp.push_back('(');
            solve(open-1,close,temp,ans);
            temp.pop_back();
            temp.push_back(')');
            solve(open,close-1,temp,ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp="";
        solve(n,n,temp,ans);
        return ans;
    }
};
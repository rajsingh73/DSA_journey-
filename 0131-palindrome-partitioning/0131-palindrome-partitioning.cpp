class Solution {
public:
    bool ispalindrom(string s){
        int low=0;
        int high=s.size()-1;
        while(low<high){
            if(s[low]!=s[high]) return false;
            low++;
            high--;
        }
        return true;
    }
    void solve(string &s,int index,vector<vector<string>> & ans,vector<string> v){
        if(index==s.size()){
            ans.push_back(v);
            return;
        }
        string ss="";
        for(int i=index;i<s.size();i++){
            ss+=s[i];
            if(ispalindrom(ss)){
                v.push_back(ss);
                solve(s,i+1,ans,v);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> v;
        solve(s,0,ans,v);
        return ans;
    }
};
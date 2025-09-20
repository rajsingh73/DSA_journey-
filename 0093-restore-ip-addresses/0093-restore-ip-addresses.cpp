class Solution {
public:
    void solve(string &s,vector<string> & ans,int index,string temp,int dotcount){
        if(temp.size()>15 || dotcount>4) return;
        if(index==s.size() && dotcount==4){
            ans.push_back(temp);
            return;
        }
        if(index!=0) temp.push_back('.');
        if(temp.size()==15) return;
        string total="";
        for(int j=index;j<s.size() && j<index+3;j++){
            if(!isdigit(s[j])) return;
            total.push_back(s[j]);
            if(j==index && s[j]-'0'==0){
                temp.push_back(s[j]);
                solve(s,ans,j+1,temp,dotcount+1);
                return;
            }
            if(stoi(total)>255) return;
            temp.push_back(s[j]);
            solve(s,ans,j+1,temp,dotcount+1);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string temp="";
        solve(s,ans,0,temp,0);
        return ans;
    }
};
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string s;
        for(int i=0;i<=path.size();i++){
            if(i==path.size() || path[i]=='/'){
                if(s=="" || s=="."){}
                else if(s=="..") {
                    if(st.size()) st.pop_back();
                }
                else st.push_back(s);
                s="";
            }
            else s+=path[i];
        }
        if(st.empty()) return "/";
        string ans="";
        for(auto it: st) ans+=("/"+it);
        return ans;
    }
};
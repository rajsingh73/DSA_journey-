class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> mp;
        map<char,char> first;
        int i=0;
        while(i<s.size()){
            if(mp.find(t[i])==mp.end() && first.find(s[i])==first.end()){
                mp[t[i]] = s[i];
                first[s[i]]=t[i];
            }
            else if((mp.find(t[i])!=mp.end() && first.find(s[i])!=first.end()) && (mp[t[i]]==s[i] && first[s[i]]==t[i])){
                i++;
                continue;
            }
            else return false;
            i++;
        }
        return true;
        
    }
};
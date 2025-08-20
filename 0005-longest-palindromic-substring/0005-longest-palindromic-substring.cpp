class Solution {
public:
    bool isvalid(int start,int end,string s){
        while(start<end){
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        map<char,vector<int>> mp;
        int start=0;
        int end=0;
        int length=0;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])!=mp.end()){
                for(auto it: mp[s[i]]){
                    if(isvalid(it,i,s)){
                        int templength=i-it+1;
                        if(templength>length){
                            start=it;
                            end=i;
                            length=templength;
                        }
                    }
                }
            }
            mp[s[i]].push_back(i);
        }
        return s.substr(start,end-start+1);
    }
};
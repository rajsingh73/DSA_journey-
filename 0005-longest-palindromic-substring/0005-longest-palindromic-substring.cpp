class Solution {
public:
    bool palindrome(string s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        map<char,vector<int>> mp;
        int ans=0;
        int start=0;
        int end=0;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])!=mp.end()){
                for(auto it:mp[s[i]]){
                    if(palindrome(s,it,i)){
                        if(i-it+1>ans){
                            ans=i-it+1;
                            start=it;
                            end=i;
                        }
                        break;
                    }
                }
            }
            mp[s[i]].push_back(i);
        }
        if(start==0 && end==0) return s.substr(0,1);
        else return s.substr(start,ans);
    }
};
class Solution {
public:
    bool ispalindrome(int i,int j,string &s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        if(s.size()==1) return s;
        int i=0;
        int ans=0;
        int start=0;
        map<char,vector<int>> mp;
        while(i<s.size()){
            if(mp.count(s[i])){
                for(auto it: mp[s[i]]){
                    if(ispalindrome(it,i,s)){
                        if(ans<i-it+1){
                            ans=i-it+1;
                            start=it;
                        }
                        break;
                    } 
                }
            }
            mp[s[i]].push_back(i);
            i++;
        }
        return s.substr(start,ans);
    }
};
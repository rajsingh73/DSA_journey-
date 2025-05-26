class Solution {
public:
    bool palindrom(string & s,int start,int end){
        while(start<end){
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }
        if(start==end || start>end) return true;
        return false;
    }
    string longestPalindrome(string s) {
        unordered_map<char,vector<int>> mp;
        int maxi=INT_MIN;
        int start=0;
        int end=0;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])!=mp.end()){
                for(int j=0;j<mp[s[i]].size();j++){
                    if(palindrom(s,mp[s[i]][j],i)){
                        if(maxi<i-mp[s[i]][j]+1){
                            maxi=i-mp[s[i]][j]+1;
                            start=mp[s[i]][j];
                            end=i;
                        }
                        break;
                    }
                }
                mp[s[i]].push_back(i);
            }
            else{
                mp[s[i]].push_back(i);
            }
        }
        string ans="";
        for(int i=start;i<=end;i++){
            ans+=s[i];
        }
        return ans;
        
    }
};
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        int ans=0;
        int i=0;
        int j=0;
        while(j<s.size()){
            if(mp.find(s[j])!=mp.end()){
                while(mp.find(s[j])!=mp.end()){
                    mp.erase(s[i]);
                    i++;
                }
            }
            mp[s[j]]++;
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
        
    }
};
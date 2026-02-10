class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        int i=0;
        int j=0;
        int ans=0;
        while(j<s.size()){
            mp[s[j]]++;
            if(mp.size()==j-i+1){
                ans=max(ans,j-i+1);
            }
            else{
                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
                i++;
            }
            j++;
        }
        return ans; 
    }
};
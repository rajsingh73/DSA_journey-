class Solution {
public:
    bool valid(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    bool isvalid(map<char,int> & mp){
        if(mp.size()<5) return false;
        for(auto  it: mp){
            if(it.second<1) return false;
        }
        return true;
    }
    int countVowelSubstrings(string s) {
        int i=0;
        int n=s.size();
        int ans=0;
        while(i<n){
            while(i<n && !valid(s[i])) i++;
            map<char,int> mp;
            int start=i;
            while(i<n && valid(s[i])){
                mp[s[i]]++;
                if(isvalid(mp)) ans++;
                i++;
            }
            i=start+1;
        }
        return ans;
    }
};
class Solution {
public:
    int maxDifference(string s) {
        map<char,int> mp;
        for(int i=0;i<s.size();i++) mp[s[i]]++;
        int oddmin=INT_MIN;
        int evenmax=INT_MAX;
        for(auto it:mp){
            if(it.second%2==0){
                evenmax=min(evenmax,it.second);
            }
            else{
                oddmin=max(oddmin,it.second);
            }
        }
        return oddmin-evenmax;
    }
};
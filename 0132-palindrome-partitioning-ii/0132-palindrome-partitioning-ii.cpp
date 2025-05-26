class Solution {
public:
    bool palindorm(int start,int end,string &s){
        while(start<end){
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }
        if(start==end || start>end) return true;
        return false;
    }
    int minCut(string s) {
        int n=s.size();
        vector<int> dp(n+1);
        dp[n]=0;
        for(int start=n-1;start>=0;start--){
            int ans=INT_MAX;
            for(int i=start;i<s.size();i++){
                if(palindorm(start,i,s)){
                    int way=1+dp[i+1];
                    ans=min(ans,way);
                }
            }
            dp[start]=ans;
        }
        return dp[0]-1;
    }
};
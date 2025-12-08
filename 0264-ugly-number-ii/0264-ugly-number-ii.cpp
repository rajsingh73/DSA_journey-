class Solution {
public:
    int nthUglyNumber(int n) {
        int twocount=0;
        int threecount=0;
        int fivecount=0;
        vector<int> dp(n);
        int index=1;
        dp[0]=1;
        while(index<n){
            int fromtwo=2*dp[twocount];
            int fromthree=3*dp[threecount];
            int fromfive=5*dp[fivecount];
            int uglynumber=min({fromtwo,fromthree,fromfive});
            if(uglynumber==fromtwo) twocount++;
            if(uglynumber==fromthree) threecount++;
            if(uglynumber==fromfive) fivecount++;
            dp[index]=uglynumber;
            index++;
        }
        return dp[n-1];
        
    }
};
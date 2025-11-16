class Solution {
public:
    int countHomogenous(string s) {
        long long ans=0;
        int n=s.size();
        int i=0;
        long long m=1e9+7;
        while(i<n){
            char c=s[i];
            long long count=0;
            while(i<n && s[i]==c){
                i++;
                count++;
            }
            long long val=((count*(count+1))/2)%m;
            ans=(ans+val)%m;
        }
        return ans;
    }
};
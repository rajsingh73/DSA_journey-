class Solution {
public:
    string longestPrefix(string s) {
        int n=s.size();
        vector<int> lps(n);
        lps[0]=0;
        int length=0;
        int j=1;
        while(j<n){
            if(s[j]==s[length]){
                length++;
                lps[j]=length;
                j++;
            }
            else{
                if(length==0){
                    lps[j]=length;
                    j++;
                }
                else{
                    length=lps[length-1];
                }
            }
        }
        for(auto it: lps) cout<<it<<" ";
        return s.substr(0,lps[n-1]);
    }
};
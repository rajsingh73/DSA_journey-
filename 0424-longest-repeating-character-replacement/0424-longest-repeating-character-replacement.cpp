class Solution {
public:
    int characterReplacement(string s, int k) {
        int arr[26]={0};
        int maxf=0;
        int maxl=0;
        int l=0;
        int r=0;
        while(r<s.size()){
            arr[s[r]-'A']++;
            maxf=max(maxf,arr[s[r]-'A']);
            if(r-l+1-maxf>k){
                arr[s[l]-'A']--;
                l++;
            }
            if(r-l+1-maxf<=k){
                maxl=max(maxl,r-l+1);
            }
            r++;
        }
        return maxl;
        
    }
};

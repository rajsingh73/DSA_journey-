class Solution {
public:
    bool isvowel(char c){
        return c=='A' || c=='a' || c=='E' || c=='e' || c=='I' || c=='i' || c=='O' || c=='o' || c=='U' || c=='u';
    }
    int maxVowels(string s, int k) {
        int i=0;
        int ans=0;
        int temp=0;
        for(int j=0;j<k;j++){
            if(isvowel(s[j])) temp++;
        }
        ans=max(ans,temp);
        int j=k;
        while(j<s.size()){
            if(isvowel(s[i])) temp--;
            i++;
            if(isvowel(s[j])) temp++;
            j++;
            ans=max(ans,temp);
        }
        return ans;

        
    }
};
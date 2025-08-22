class Solution {
public:
    bool isvowel(char c){
        return c=='A' || c=='a' || c=='E' || c=='e' || c=='I' || c=='i' || c=='O' || c=='o' || c=='U' || c=='u';
    }
    string reverseVowels(string s) {
        int i=0;
        int j=s.size()-1;
        while(i<j){
            while(i<s.size()){
                if(isvowel(s[i])) break;
                i++;
            }
            while(j>=0){
                if(isvowel(s[j])) break;
                j--;
            }

            if(i<j){
                char temp=s[i];
                s[i]=s[j];
                s[j]=temp;
                i++;
                j--;
            }
        }
        return s;
        
    }
};
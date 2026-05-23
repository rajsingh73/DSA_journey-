class Solution {
public:
    bool isPalindrome(string s) {
        int i=0;
        int l=s.size()-1;
        while(i<l){
            while(i<l && !isalnum(s[i])) i++;
            while(i<l && !isalnum(s[l])) l--;
            cout<<s[i]<<" "<<s[l]<<endl;
            if(tolower(s[i])!=tolower(s[l])) return false;
            i++;
            l--;
        }
        return true;
        
    }
};
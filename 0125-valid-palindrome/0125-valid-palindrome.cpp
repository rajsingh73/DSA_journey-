class Solution {
public:
    bool check(char first,char second){
        return tolower(first)==tolower(second);
    }
    bool isPalindrome(string s) {
        int start=0;
        int end=s.size()-1;
        while(start<end){
            while(start<end && !isalnum(s[start])){
                start++;
            }
            while(end>start && !isalnum(s[end])) end--;
            if(!check(s[start],s[end])) return false;
            start++;
            end--;
        }
        return true;
        
    }
};
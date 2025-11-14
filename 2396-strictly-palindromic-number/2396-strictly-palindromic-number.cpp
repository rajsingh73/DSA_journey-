class Solution {
public:
    bool ispal(string s){
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    string ba(int n,int i){
        string s="";
        while(n>0){
            int rem=n%i;
            s.push_back(rem);
            n=n/i;
        }
        return s;
    }
    bool isStrictlyPalindromic(int n) {
        for(int i=2;i<=n-2;i++){
            if(n%i==0) return false;
            string s=ba(n,i);
            if(!ispal(s)) return false;
        }
        return true;
        
    }
};
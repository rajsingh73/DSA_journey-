class Solution {
public:
    bool isNumber(string s) {
        int n=s.size();
        int i=0;
        while(i<n && s[i]==' ') i++;
        if(i<n && (s[i]=='-' || s[i]=='+')) i++;
        bool hasexp=false;
        bool digit=false;
        bool hasdot=false;
        while(i<n){
            if(isdigit(s[i])){
                digit=true;
            }
            else if(s[i]=='.'){
                if(hasdot || hasexp) return false;
                hasdot=true;
            }
            else if(s[i]=='e' || s[i]=='E'){
                if(hasexp || !digit) return false;
                hasexp=true;
                digit=false;
                if(i+1<n && (s[i+1]=='-' || s[i+1]=='+')) i++;
            }
            else return false;
            i++;
        }
        return digit;
        
    }
};
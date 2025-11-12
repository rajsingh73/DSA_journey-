class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int n=s.size();
        while(i<n && s[i]==' ') i++;
        bool positive=true;
        if(s[i]=='+') i++;
        else if(s[i]=='-'){
            i++;
            positive=false;
        }
        while(i<n && s[i]=='0') i++;
        long long val=0;
        while(i<n && isdigit(s[i])){
            val=(val*10)+(s[i]-'0');
            if(!positive && val>INT_MAX) return INT_MIN;
            else if(val>INT_MAX) return INT_MAX;
            i++;
        }
        if(!positive) return -1*val;
        return val;
    }
};
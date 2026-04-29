class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int sign=1;
        while(i<s.size()  && s[i]==' ') i++;
        if(s[i]=='-'){
            sign=-1;
            i++;
        }
        else if(s[i]=='+') i++;
        while(i<s.size() && s[i]=='0') i++;
        int ans=0;
        while(i<s.size() && isdigit(s[i])){
            int digit=s[i]-'0';
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > 7)) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            ans=(ans*10)+digit;
            cout<<ans<<endl;
            i++;
        }
        return ans*sign;
    }
};
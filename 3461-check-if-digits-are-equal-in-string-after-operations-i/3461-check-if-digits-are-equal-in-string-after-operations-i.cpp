class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.size()!=2){
            int i=0;
            while(i<s.size()-1){
                int val=((s[i]-'0')+s[i+1]-'0');
                s[i]=(val%10+'0');
                i++;
            } 
            s.pop_back();
        }
        return s[0]==s[1];
    }
};
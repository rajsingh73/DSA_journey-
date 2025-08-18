class Solution {
public:
    string reverseWords(string s) {
        int i=s.size()-1;
        string ans="";
        int first=0;
        while(i>=0){
            while(i>=0 && s[i]==' ') i--;
            int temp=i;
            int count=0;
            while(i>=0 && s[i]!=' ') {
                i--;
                count=1;
            }
            if(count==1){
                if(first!=0) ans+=" ";
                ans+=s.substr(i+1,temp-i);
                first=1;
            }
        }
        return ans;
        
    }
};
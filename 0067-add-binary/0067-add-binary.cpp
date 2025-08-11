class Solution {
public:
    string addBinary(string a, string b) {
        int first=0;
        int n=a.size()-1;
        int m=b.size()-1;
        int second=0;
        for(int i=0;i<a.size();i++){
            int val=a[i]-'0';
            first=first|(val<<(n-i));
        }
        for(int i=0;i<b.size();i++){
            int val=b[i]-'0';
            second=second|(val<<(m-i));
        }
        int total=first+second;
        string s="";
        for(int i=31;i>=0;i--){
            int bit=(total>>i)&1;
            s.push_back(bit+'0');
        }
        int i=1;
        while(!s.empty() && s[i-1]=='0'){
            s.erase(0,1);
        }
        if(s.empty()) return "0";
        return s;

        

    }
};
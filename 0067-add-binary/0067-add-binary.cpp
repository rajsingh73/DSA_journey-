class Solution {
public:
    string addBinary(string a, string b) {
        int n=a.size();
        int m=b.size();
        int i=n-1;
        int j=m-1;
        int carry=0;
        string s="";
        while(i>=0 || j>=0 || carry){
            int sum=carry;
            if(i>=0) sum+=(a[i--]-'0');
            if(j>=0) sum+=(b[j--]-'0');
            s.push_back(char((sum%2)+'0'));
            carry=sum/2;
        }
        reverse(s.begin(),s.end());
        return s;
        
    }
};
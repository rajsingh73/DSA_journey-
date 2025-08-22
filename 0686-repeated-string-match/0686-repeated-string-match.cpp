class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n=a.size();
        int m=b.size();
        while(a.size()<m) a+=a;
        a+=a;
        vector<int> lps(m);
        int length=0;
        lps[0]=0;
        int j=1;
        while(j<m){
            if(b[j]==b[length]){
                length++;
                lps[j]=length;
                j++;
            }
            else{
                if(length==0){
                    lps[j]=0;
                    j++;
                }
                else length=lps[length-1];
            }
        }
        j=0;
        int i=0;
        while(i<a.size()){
            if(a[i]==b[j]){
                i++;
                j++;
            }
            else{
                if(j==0) i++;
                else j=lps[j-1];
            }
            if(j==m) return ((i-1)/n)+1;
        }
        return -1;

        
    }
};
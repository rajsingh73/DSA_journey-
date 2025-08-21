class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=needle.size();
        int m=haystack.size();
        vector<int> lsp(n);
        lsp[0]=0;
        int length=0;
        int j=1;
        while(j<n){
            if(needle[j]==needle[length]){
                length++;
                lsp[j]=length;
                j++;
            }
            else{
                if(length!=0){
                    length=lsp[length-1];
                }
                else{
                    lsp[j]=length;
                    j++;
                }
            }
        }
        int i=0;
        j=0;
        while(i<m){
            if(haystack[i]==needle[j]){
                i++;
                j++;
            }
            else{
                if(j!=0) j=lsp[j-1];
                else i++;
            }
            if(j==n) return i-n;
        }
        return -1;
        
    }
};
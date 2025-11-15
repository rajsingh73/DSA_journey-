class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans=0;
        int n=s.size();
        int cur=0;
        int i=0;
        int prev=0;
        while(true){
            if(s[i]=='0'){
                while(i<n && s[i]=='0'){
                    i++;
                    prev++;
                }
            }
            else{
                while(i<n && s[i]=='1'){
                    i++;
                    prev++;
                }
            }
            break;
        }
        while(i<n){
            if(s[i]=='0'){
                while(i<n && s[i]=='0'){
                    i++;
                    cur++;
                }
            }
            else{
                while(i<n && s[i]=='1'){
                    i++;
                    cur++;
                }
            }
            cout<<cur<<" "<<prev<<endl;
            ans+=min(cur,prev);
            prev=cur;
            cur=0;
        }
        return ans;  
    }
};
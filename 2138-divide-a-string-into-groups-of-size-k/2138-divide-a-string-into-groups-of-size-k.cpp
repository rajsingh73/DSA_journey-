class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        if(s.size()==k) {
            ans.push_back(s);
            return ans;
        }
        int n=s.size();
        int size=n/k;
        int z=0;
        for(int i=0;i<size;i++){
            string st="";
            for(int j=0;j<k;j++){
                st.push_back(s[z]);
                z++;
            }
            ans.push_back(st);
        }
        if(z<s.size()){
            string st="";
            for(int i=z;i<n;i++) {
                st.push_back(s[i]);
            }
            for(int i=st.size();i<k;i++){
                st.push_back(fill);
            }
            ans.push_back(st);
        }
        return ans;

        
    }
};
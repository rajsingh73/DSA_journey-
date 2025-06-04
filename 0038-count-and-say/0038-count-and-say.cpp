class Solution {
public:
    string countAndSay(int n) {
        string ans="1";
        while(n>1){
            string next;
            for(int i=0;i<ans.size();i++){
                int count=1;
                while(i+1<ans.size() && ans[i]==ans[i+1]){
                    count++;
                    i++;
                }
                next+=to_string(count)+ans[i];
            }
            ans=next;
            n--;
        }
        return ans;
        
    }
};
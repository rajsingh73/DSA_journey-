class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string  ans="";
        for(int i=0;i<strs.size();i++){
            string s=strs[i];
            if(i==0) ans=s;
            else{
                string temp="";
                int i=0;
                while(i<ans.size() && i<s.size() &&ans[i]==s[i]){
                    temp.push_back(ans[i]);
                    i++;
                }
                ans=temp;
            }

        }
        return ans;
        
    }
};
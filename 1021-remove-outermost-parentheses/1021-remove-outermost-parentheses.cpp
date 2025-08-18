class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int i=0;
        while(i<s.size()){
            string temp="";
            stack<char> st;
            st.push(s[i]);
            while(st.size()){
                i++;
                if(s[i]==')' && st.size()) st.pop();
                else st.push(s[i]);
                temp+=s[i];
            }
            temp.pop_back();
            ans+=temp;
            i++;
        }
        return ans;
        
    }
};
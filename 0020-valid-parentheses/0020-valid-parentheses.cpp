class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int i=0;
        while(i<s.size()){
            if(s[i]==')' || s[i]=='}' || s[i]==']'){
                if(st.size()==0) return false;
                else{
                    char c=st.top();
                    if((c=='(' && s[i]==')') || (c=='{' && s[i]=='}') || (c=='[' && s[i]==']')){
                        st.pop();
                    }
                    else{
                        return false;
                    }

                }
            }
            else{
                st.push(s[i]);
            }
            i++;
        }
        if(st.size()==0) return true;
        return false;
        
    }
};
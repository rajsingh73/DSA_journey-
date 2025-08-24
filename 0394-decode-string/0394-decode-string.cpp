class Solution {
public:
    string r(stack<char> & st){
        string temp="";
        st.pop();
        while(st.size() && st.top()!='['){
            if(st.top()==']') temp+=r(st);
            else {
                temp+=st.top();
                st.pop();
            }
        }
        cout<<temp<<" "<<endl;
        if(st.size() ) st.pop();
        string val="";
        while(st.size() && isdigit(st.top())){
            val+=st.top();
            st.pop();
        }
        reverse(val.begin(),val.end());
        int round=stoi(val);
        cout<<round;
        string ans="";
        for(int i=0;i<round;i++) ans+=temp;
        return ans;
    }
    string decodeString(string s) {
        stack<char> st;
        for(auto it: s) st.push(it);
        string ans="";
        while(st.size()){
            if(st.top()==']') ans+=r(st);
            else {
                ans+=st.top();
                st.pop();
            }
        }
        reverse(ans.begin(),ans.end());
        return ans; 
    }
};
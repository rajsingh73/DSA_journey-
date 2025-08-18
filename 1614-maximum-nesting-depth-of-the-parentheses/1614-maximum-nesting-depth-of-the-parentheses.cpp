class Solution {
public:
    int maxDepth(string s) {
        int size=0;
        stack<char> st;
        for(auto it: s){
            if(it=='(') st.push(it);
            else if(it==')') st.pop();
            int temp=st.size();
            size=max(size,temp);
        }
        return size;
        
    }
};
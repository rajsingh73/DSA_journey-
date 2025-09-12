class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> ans(n); 
        stack<pair<int,int>> st; 
        for(int i=0;i<n;i++){
            int val=temperatures[i];
            while(!st.empty() && st.top().first<val){
                int index=st.top().second;
                ans[index]=i-index;
                st.pop();
            }
            st.push({val,i});
        }
        while(!st.empty()){
            ans[st.top().second]=0;
            st.pop();
        }
        return ans;
    }
};
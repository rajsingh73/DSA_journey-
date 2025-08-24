class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i=0;i<asteroids.size();i++){
            if(st.empty()) st.push(asteroids[i]);
            else if(!(st.top()>0 && asteroids[i]<0)) st.push(asteroids[i]);
            else{
                int temp=asteroids[i];
                while(st.size() && (temp<0 && st.top()>0)){
                    int temp1=st.top();
                    int first=abs(temp);
                    int second=abs(temp1);
                    if(first==second){
                        st.pop();
                        temp=2000;
                        break;
                    }
                    else if(first<second) {
                        temp=2000;
                        break;
                    }
                    else{
                        st.pop();
                    }
                }
                if(temp!=2000) st.push(temp);
            }
        }
        vector<int> ans;
        while(st.size()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
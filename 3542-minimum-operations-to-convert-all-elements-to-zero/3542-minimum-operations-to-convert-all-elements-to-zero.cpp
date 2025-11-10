class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> st;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) continue;
            if(st.empty()){
                st.push(nums[i]);
                count++;
                continue;
            }
            if(nums[i]<st.top()){
                while(st.size() && st.top()>nums[i]) st.pop();
            }
            if(st.empty() || nums[i]>st.top()){
                st.push(nums[i]);
                count++;
            }
        }
        return count;
    }
};
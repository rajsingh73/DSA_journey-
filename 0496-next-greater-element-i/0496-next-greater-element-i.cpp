class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        vector<int> ng(nums2.size(),-1);
        for(int i=0;i<nums2.size();i++){
            while(st.size() && (nums2[i]>nums2[st.top()])){
                ng[st.top()]=nums2[i];
                st.pop();
            }
            st.push(i);
        }
        map<int,int> mp;
        for(int i=0;i<nums2.size();i++){
            mp[nums2[i]]=i;
        }
        vector<int> ans;
        for(auto it: nums1){
            ans.push_back(ng[mp[it]]);
        }
        for(auto it: ng) cout<<it<<" ";
        cout<<endl;
        return ans;
        
    }
};
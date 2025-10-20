class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size()-1;
        if(nums.size()==1) return {nums[0]};
        vector<int> ans;
        if(nums[0]!=nums[1] && nums[0]+1!=nums[1])  ans.push_back(nums[0]);
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i]==nums[i-1] || nums[i]-1==nums[i-1]) continue;
            if(nums[i]==nums[i+1] || nums[i]+1==nums[i+1]) continue;
            ans.push_back(nums[i]);
        }
        if(nums[n]!=nums[n-1] && nums[n]-1!=nums[n-1]) ans.push_back(nums[n]);
        return ans;
        
    }
};
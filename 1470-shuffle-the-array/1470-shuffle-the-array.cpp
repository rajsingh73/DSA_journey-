class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int left=0;
        int right=nums.size()/2;
        vector<int> ans;
        while(right<nums.size()){
            ans.push_back(nums[left]);
            ans.push_back(nums[right]);
            left++;
            right++;
        }
        return ans;
    }
};
class Solution {
public:
    void solve(vector<int> &nums,int target,int &ans,int val,int index){
        if(index==-1){
            if(val==target) ans++;
            return;
        }
        solve(nums,target,ans,val+nums[index],index-1);
        solve(nums,target,ans,val-nums[index],index-1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans=0;
        solve(nums,target,ans,0,nums.size()-1);
        return ans;
    }
};
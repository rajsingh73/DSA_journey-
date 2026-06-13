class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> ans(nums.size(),-1);
        int d = 2*k+1;
        if(d > nums.size()){
            return ans;
        }
        long sum = 0;
        for(int i = 0;i<nums.size();i++){
            if(i == d-1){
                sum+=nums[i];
                long avg = sum/d;
                ans[k++] = avg;
            }
            else if(i >= d){
                sum-=nums[i-d];
                sum+=nums[i];
                long avg = sum/d;
                ans[k++] = avg;
            }
            else{
                sum+=nums[i];
            }
        }
        return ans;
    }
};

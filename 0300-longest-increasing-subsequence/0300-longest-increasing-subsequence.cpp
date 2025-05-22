class Solution {
public:
    int lower(vector<int> & ans,int target){
        int low=0;
        int high=ans.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(ans[mid]>=target) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(ans.empty()) ans.push_back(nums[i]);
            else if(ans.back()<nums[i]) ans.push_back(nums[i]);
            else{
                int last=lower(ans,nums[i]);
                ans[last]=nums[i];
            }
        }
        return ans.size();
        
    }
};
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]>=target) high=mid-1;
            else low=mid+1;
        }
        int first=low;
        low=0;
        high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]<=target) low=mid+1;
            else high=mid-1;
        }
        int second=high;
        if(first!=nums.size() && second!=-1){
            if(nums[first]==target){
                return {first,second};
            }
            else{
                return {-1,-1};
            }
        }
        else return {-1,-1};
    }
};
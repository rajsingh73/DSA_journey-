class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        long long prefixmul=1;
        int left=0;
        int right=0;
        long long ans=0;
        while(right<nums.size()){
            prefixmul*=nums[right];
            while(left<=right && prefixmul>=k){
                prefixmul=prefixmul/nums[left];
                left++;
            }
            ans+=(right-left+1);
            right++;
        }
        return ans;
    }
};
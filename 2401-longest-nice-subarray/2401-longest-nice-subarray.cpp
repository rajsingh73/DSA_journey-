class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int left=0;
        int right=1;
        int ans=1;
        while(right<nums.size()){
            int i=left;
            while(i<right){
                if((nums[i]&nums[right])!=0) left=i+1;
                i++;
            }
            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};
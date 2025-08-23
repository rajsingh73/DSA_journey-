class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0;
        int j=0;
        int ans=0;
        int nonone=0;
        while(j<nums.size()){
            if(nums[j]!=1) nonone++;
            while(nonone>1){
                if(nums[i]!=1) nonone--;
                i++;
            }
            ans=max(ans,j-i);
            j++;
        }
        return ans;
    }
};
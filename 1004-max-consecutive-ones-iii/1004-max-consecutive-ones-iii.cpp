class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int ans=0;
        int zerocount=0;
        while(j<nums.size()){
            if(nums[j]==0) zerocount++;
            while(zerocount>k){
                if(nums[i]==0) zerocount--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
        
    }
};
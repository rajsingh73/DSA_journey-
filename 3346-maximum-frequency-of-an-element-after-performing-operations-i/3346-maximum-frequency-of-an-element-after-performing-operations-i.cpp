class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int left=0,res=1;
        sort(nums.begin(),nums.end());
        for(int right=0;right<nums.size();right++){
            while(nums[right]-nums[left]>2*k){
                left++;
            }
            int ws=right-left+1;
            res=max(res,min(ws,numOperations+1));
        }
        return res;
    }
};
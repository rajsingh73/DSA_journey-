class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        int i=0;
        while(i<n){
            if(nums[i]==0){
                int count=1;
                while(i<n && nums[i]==0){
                    ans+=count;
                    count++;
                    i++;
                }
            }
            i++;
        }
        return ans;
    }
};
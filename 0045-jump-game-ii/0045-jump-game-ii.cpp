class Solution {
public:
    int jump(vector<int>& nums) {
        int r=0;
        int l=0;
        int jump=0;
        while(r<nums.size()-1){
            int fast=0;
            for(int i=l;i<=r;i++){
                fast=max(fast,i+nums[i]);
            }
            l=r;
            r=fast;
            jump++;
        }
        return jump;
    }
};
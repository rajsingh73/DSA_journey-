class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int ma=nums[0];
        int dif=INT_MIN;
        long long result=INT_MIN;
        for(int i=1;i<nums.size()-1;i++){
            dif=max(dif,ma-nums[i]);
            ma=max(ma,nums[i]);
            result=max(result,(long long)dif*nums[i+1]);
        }
        if(result<0) return 0;
        return result;
    }
};
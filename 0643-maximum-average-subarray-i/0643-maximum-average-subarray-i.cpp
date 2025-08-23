class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i=0;
        double sum=0;
        for(int j=0;j<k;j++){
            sum+=nums[j];
        }
        double ans=sum/k;
        int j=k;
        while(j<nums.size()){
            sum=sum-nums[i]+nums[j];
            i++;
            j++;
            ans=max(ans,sum/k);
        }
        return ans;
    }
};
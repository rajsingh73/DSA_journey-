class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans=0;
        double sum=0;
        for(int i=0;i<k;i++) sum+=nums[i];
        ans=sum/k;
        int i=0;
        int j=k;
        while(j<nums.size()){
            sum-=nums[i];
            sum+=nums[j];
            ans=max(ans,sum/k);
            i++;
            j++;
        }
        return ans;
        
    }
};
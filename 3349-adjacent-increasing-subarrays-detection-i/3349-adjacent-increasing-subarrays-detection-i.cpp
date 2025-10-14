class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int i=0;
        int n=nums.size();
        while(i<=(n-2*k)){
            int j=i+k;
            int temp=i+k;
            int first=nums[i];
            int firstnew=nums[j];
            i++; j++;
            while(i<=temp){
                if(i==temp) return true;
                if(first>=nums[i]) break;
                if(firstnew>=nums[j]) break;
                first=nums[i];
                firstnew=nums[j];
                i++;
                j++;
            }
        }
        return false;
        
    }
};
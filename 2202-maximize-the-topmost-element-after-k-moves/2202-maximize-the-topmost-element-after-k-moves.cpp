class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==0) return nums[0];
        if(n==1) return -1;
        if(k>n) k=n+1;
        int maxi=0;
        int i=0;
        while(i<n && k>1){
            maxi=max(maxi,nums[i]);
            k--;
            i++;
        }
        if(i==n) return maxi;
        if(i<n-1) return max(maxi,nums[i+1]);
        return maxi;        
    }
};
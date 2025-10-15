class Solution {
public:
    bool ispossible(vector<int> & nums,int k){
        int i=0;
        int j=i+k;
        int n=nums.size()-2*k;
        while(i<=n){
            int temp=i;
            temp=i+k;
            int first=nums[i];
            int second=nums[j];
            j++; i++;
            while(j<nums.size()){
                if(i==temp) return true;
                if(nums[i]<=first) break;
                if(nums[j]<=second) break;
                first=max(first,nums[i]);
                second=max(second,nums[j]);
                i++;
                j++;
            }
            if(i==temp) return true;
        }
        return false;
    }
    int maxIncreasingSubarrays(vector<int>& nums) {
        int  low=1;
        int high=nums.size()/2;
        int ans=1;
        while(low<=high){
            int mid=(low+high)/2;
            if(ispossible(nums,mid)){
                low=mid+1;
                ans=max(ans,mid);
            }
            else high=mid-1;
        }
        return ans;
        
    }
};
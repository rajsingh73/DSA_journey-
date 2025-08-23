class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre(n);
        int pree=0;
        for(int i=0;i<nums.size();i++){
            pre[i]=pree;
            pree+=nums[i];
        }
        int ans=INT_MAX;
        int suf=0;
        for(int i=nums.size()-1;i>=0;i--){
            if(suf==pre[i]) ans=min(ans,i);
            suf+=nums[i];
        }
        if(ans!=INT_MAX) return ans;
        return -1;   
    }
};
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0;
        int temp=0;
        for(int it:nums){
            if(it==0) temp=0;
            else temp++;
            ans=max(ans,temp);
        }
        return ans;
        
    }
};
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxi=nums[0];
        int i=0;
        int n=nums.size()-1;
        while(i<=maxi){
            if(maxi>=n) return true;
            maxi=max(maxi,i+nums[i]);
            i++;
        }
        if(maxi>=n) return true;
        return false;
        
    }
};
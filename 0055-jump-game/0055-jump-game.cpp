class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i=0;
        int maxi=0;
        while(i<=maxi && maxi<nums.size()-1){
            maxi=max(maxi,i+nums[i]);
            i++;
        }
        if(maxi>=nums.size()-1) return true;
        else return false;
        
    }
};
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int i=0;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        while(i<n){
            if(nums[i]==original) original*=2;
            i++;
        }
        return original;
        
    }
};
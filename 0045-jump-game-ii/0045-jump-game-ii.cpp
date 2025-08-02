class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int maxi=nums[0];
        int prev=0;
        int count=1;
        while(maxi<nums.size()-1){
            int temp=maxi;
            for(int i=prev;i<=maxi;i++){
                temp=max(temp,i+nums[i]);
            }
            count++;
            prev=maxi;
            maxi=temp;
        }
        return count;
        
    }
};
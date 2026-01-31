class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int i=0;
        int maxi=nums[0];
        int count=1;
        while(maxi<nums.size()-1){
            int tempmaxi=0;
            int tempi=0;
            for(int temp=i+1;temp<=maxi;temp++){
                if(tempmaxi<nums[temp]+temp){
                    tempmaxi=nums[temp]+temp;
                    i=temp;
                }
            }
            count++;
            i=tempi;
            maxi=tempmaxi;
        }
        return count;
    }
};
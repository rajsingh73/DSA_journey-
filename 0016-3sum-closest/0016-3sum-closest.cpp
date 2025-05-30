class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int def=INT_MAX;
        int ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                int val=nums[i]+nums[j]+nums[k];
                if(def>abs(val-target)){
                    def=abs(val-target);
                    ans=val;
                }
                if(val==target) break;
                else if(val<target){
                    j++;
                    while(j<nums.size() && nums[j]==nums[j-1]) j++;
                }
                else{
                    k--;
                    while(k>i && nums[k]==nums[k+1]) k--;
                }

            }
        }
        return ans;
    }
};
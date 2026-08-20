class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                l=0;
            }
            else{
                l++;
                ans=max(ans,l);
                cout<<i<<" "<<l<<endl;
            }
        }
        return ans;
        
    }
};
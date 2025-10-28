class Solution {
public:
    bool solve(int index,int val,vector<int> &temp){
        vector<int> nums=temp;
        while(index>=0 && index<nums.size()){
            if(val==0){
                if(nums[index]>0){
                    nums[index]--;
                    index++;
                    val=1;
                }
                else index--;
            }
            else{
                if(nums[index]>0){
                    nums[index]--;
                    index--;
                    val=0;
                }
                else index++;
            }
        }
        for(auto it: nums){
            if(it!=0) return false;
        }
        return true;
    }
    int countValidSelections(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                if(solve(i,0,nums)) ans++;
                if(solve(i,1,nums)) ans++;
            }
        }
        return ans;
    }
};
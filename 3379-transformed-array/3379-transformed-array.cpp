class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) ans.push_back(nums[i]);
            else if(nums[i]>0){
                int index=i+nums[i];
                index=index%n;
                ans.push_back(nums[index]);
            }
            else{
                int index=i+nums[i];
                if(index>=0) ans.push_back(nums[index]);
                else{
                    int absi=abs(index);
                    absi=absi%n;
                    if(absi==0) ans.push_back(nums[0]);
                    else ans.push_back(nums[n-absi]);
                }
            }
        }
        return ans;    
    }
};
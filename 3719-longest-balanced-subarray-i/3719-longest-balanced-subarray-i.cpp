class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                set<int> even;
                set<int> odd;
                for(int k=i;k<=j;k++){
                    if(nums[k]%2==0) even.insert(nums[k]);
                    else odd.insert(nums[k]);
                }
                if(even.size()==odd.size()) ans=max(ans,j-i+1);
            }
        }
        return ans;  
    }
};
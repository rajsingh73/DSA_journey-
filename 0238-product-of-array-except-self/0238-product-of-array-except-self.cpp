class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int productfront=1;
        int n=nums.size();
        int productback=1;
        int backstart=n-1;
        vector<int> ans(n,1);
        for(int i=0;i<n;i++){
            ans[i]*=productfront;
            ans[backstart-i]*=productback;
            productfront*=nums[i];
            productback*=nums[backstart-i];
        }
        return ans;
        
    }
};
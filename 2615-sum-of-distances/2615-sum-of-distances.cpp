class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n=nums.size();
        vector<long long> ans(n,0);
        unordered_map<int,int> count;
        unordered_map<int,long long> sum;
        for(int i=0;i<n;i++){
            int x=nums[i];
            if(count[x]>0) ans[i]+=1LL*count[x]*i-sum[x];
            count[x]++;
            sum[x]+=i;
        }
        count.clear();
        sum.clear();
        for(int i=n-1;i>=0;i--){
            int x=nums[i];
            if(count[x]>0) ans[i]+=sum[x]-count[x]*1LL*i;
            count[x]++;
            sum[x]+=i;
        }
        return ans;
    }
};

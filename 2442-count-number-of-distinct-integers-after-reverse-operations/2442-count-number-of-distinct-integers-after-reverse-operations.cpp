class Solution {
public:
    int rev(int n){
        int ans=0;
        while(n>0){
            int rem=n%10;
            if(ans==0 && rem==0){
                n=n/10;
                continue;
            }
            ans=(ans*10)+rem;
            n=n/10;
        }
        return ans;
    }
    int countDistinctIntegers(vector<int>& nums) {
        set<int> st;
        for(int i=0;i<nums.size();i++){
            int re=rev(nums[i]);
            cout<<re<<" ";
            st.insert(re);
            st.insert(nums[i]);
        }
        return st.size();
    }
};
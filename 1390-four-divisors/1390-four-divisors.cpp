class Solution {
public:
    int sumdiv(int n){
        int count=0;
        int sum=0;
        for(int i=1;i<=n;i++){
            if(count>4) return 0;
            if(n%i==0){
                sum+=i;
                count++;
            }
        }
        return count==4?sum:0;

    }
    int sumFourDivisors(vector<int>& nums) {
        int ans=0;
        for(auto it: nums) ans+=sumdiv(it);
        return ans;
    }
};
class Solution {
    public int totalMoney(int n) {
        int mul=n/7;
        int ans=0;
        ans+=(28*mul);
        for(int i=1;i<=mul-1;i++){
            ans+=(7*i);
        }
        int rem=n%7;
        int count=mul+1;
        for(int i=0;i<rem;i++){
            ans+=count;
            count++;
        }
        return ans;
    }
}
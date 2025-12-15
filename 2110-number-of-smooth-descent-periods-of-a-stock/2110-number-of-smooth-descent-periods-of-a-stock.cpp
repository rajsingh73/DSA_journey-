class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans=prices.size();
        int n=prices.size();
        int i=1;
        while(i<n){
            int prev=prices[i-1];
            long long count=1;
            while(i<n && prev==prices[i]+1){
                prev=prices[i];
                count++;
                i++;
            }
            if(count>1){
                ans-=count;
                if(count%2==0){
                    long long sum=count+1;
                    count=count/2;
                    ans+=(count*sum)*1LL;
                }
                else{
                    long long sum=count+1;
                    sum=sum/2;
                    ans+=(count*sum);
                }
            }
            i++;
        }
        return ans;
    }
};
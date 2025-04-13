class Solution {
public:
    long long power(int x,long long n){
        if(n==0) return 1;
        int mod=1e9+7;
        long long f=power(x,n/2)%mod;
        return (n%2==0)? (f*f)%mod:(f*f*x)%mod;
    }
    int countGoodNumbers(long long n) {
        long long even=(n+1)/2;
        long long odd=n/2;
        int mod=1e9+7;
        long long evensum=power(5,even);
        long long oddsum=power(4,odd);
        return (evensum*oddsum)%mod;
    }
};
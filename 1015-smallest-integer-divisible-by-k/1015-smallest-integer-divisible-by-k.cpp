class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2==0 || k%5==0) return -1;
        long long ans=0;
        int count=0;
        while(true){
            while(ans<k){
                ans=(ans*10)+1;
                count++;
            }
            if(ans%k==0) return count;
            ans=(ans%k);
        }
        return -1;
    }
};
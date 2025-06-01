class Solution {
public:
    int divide(int divident, int divisor){
        if(divident == divisor){
            return 1;
        }
        if(divisor==1){
            return divident;
        }
        if(divident == INT_MIN && divisor == -1) return INT_MAX;
        bool sign = true;
        if(divident < 0 && divisor > 0){
            sign=false;
        }
        if(divident >= 0 && divisor < 0){
            sign= false;
        }
        long n=abs(divident);
        long m=abs(divisor);
        long ans=0;
        while(n>=m){
            int count=0;
            while(n>=(m<<(count+1))){
                count++;
            }
            ans=ans+(1<<count);
            n=n-(m<<count);
        }
        ans=sign?ans:(-1*ans);
        if(ans==INT_MIN) return INT_MIN;
        if(ans==INT_MAX) return INT_MAX;
        return ans;
    }
};
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor) return 1;
        bool sign=false;
        if(dividend<0 && divisor>0) sign=true;
        if(dividend>0 && divisor<0) sign=true;
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;
        if(dividend==INT_MIN && divisor==1) return INT_MIN;
        long n=abs((long)dividend);
        long d=abs((long)divisor);
        long ans=0;
        while(n>=d){
            long count=0;
            while(n>=(d<<(count+1))) count++;
            ans=ans+(1<<count);
            n=n-(d<<count);
        }
        if(ans==INT_MAX && sign) return INT_MIN-1;
        if(ans==INT_MIN && sign) return INT_MAX;
        return sign?-1*ans:ans;
        
    }
};
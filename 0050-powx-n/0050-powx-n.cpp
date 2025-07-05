class Solution {
public:
    double power(double x,int n){
        if(n==0) return 1;
        double f=power(x,n/2);
        return (n%2==0)?f*f:f*f*x;
    }
    double myPow(double x, int n) {
        if(n<0){
            if(n==INT_MIN){
                x=x*x;
                n=INT_MAX;
            }
            else{
                n=-n;
            }
            x=1/x;
        }
        return power(x,n);
    }
};
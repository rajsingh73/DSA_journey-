class Solution {
public:
    int reverse(int x) {
        if(x==INT_MIN) return 0;
        int a=0;
        int c=1;
        if(x<0){
            c=-1;
            x=x*-1;
        }
        while(x>0){
            if(a>INT_MAX/10) return 0;
            if(a<INT_MIN/10) return 0;
            a=a*10+x%10;
            x=x/10;
        }
        return c*a;
    }
};
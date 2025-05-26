class Solution {
public:
    int reverse(int x) {
        int a=0;
        if(x==INT_MIN) return 0;
        while(x!=0){
            if(a>INT_MAX/10){
                return false;
            }
            if(a<INT_MIN/10){
                return false;
            }
            a=a*10+x%10;
            x=x/10;
        }
        return a;
        
    }
};
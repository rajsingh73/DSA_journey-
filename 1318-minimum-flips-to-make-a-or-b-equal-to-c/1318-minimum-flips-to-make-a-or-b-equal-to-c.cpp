class Solution {
public:
    int solve(int a,int b,int m){
        int count=0;
        while(a || b){
            int rema=a%2;
            int remb=b%2;
            int remm=m%2;
            if(a) a=a/2;
            if(b) b=b/2;
            if(m) m=m/2;
            if(rema==remb) continue;
            if(rema==1 && remm==1) count+=2;
            else count++;
        }
        return count;
    }
    int minFlips(int a, int b, int c) {
        int d=a|b;
        int m=a&b;
        return solve(d,c,m);
        
    }
};
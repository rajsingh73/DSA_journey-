class Solution {
public:
    bool isprime(int n){
        for(int i=2;i<sqrt(n);i++){
            if(n%i==0) return false;
        }
        return true;
    }
    int minSteps(int n) {
        int count=0;
        for(int i=2;i<=n;i++){
            if(n%i==0){
                if(isprime(i)){
                    while(n>0 && n%i==0){
                        n=n/i;
                        count+=i;
                    }
                }
            }
        }
        return count;
        
    }
};
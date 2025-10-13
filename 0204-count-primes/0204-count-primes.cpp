class Solution {
public:
    int countPrimes(int n) {
        if(n==0 || n==1) return 0;
        vector<int>v (n,1);
        int s=sqrt(n);
        v[0]=v[1]=0;
        for(int i=2;i<=s;i++){
            int j=i*i;
            while(j<n){
                v[j]=0;
                j+=i;
            }
        }
        int count=0;
        for(auto it: v){
            if(it==1) count++;
        }
        return count;
        
    }
};
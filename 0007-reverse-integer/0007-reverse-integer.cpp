class Solution {
public:
    int reverse(int x) {
        if(x==0) return x;
        int first=1;
        int ans=0;
        while(x){
            int rem=x%10;
            x=x/10;
            cout<<ans<<endl;
            if(first && rem==0) continue;
            if(ans<(INT_MIN/10)) return 0;
            if(ans>(INT_MAX/10) ) return 0;
            if(ans==(INT_MIN/10) && rem>8) return 0;
            if(ans==(INT_MAX/10) && rem>7) return 0;
            ans=(ans*10)+rem;
            first=0;
        }
        cout<<ans<<endl;
        return ans;
    }
};
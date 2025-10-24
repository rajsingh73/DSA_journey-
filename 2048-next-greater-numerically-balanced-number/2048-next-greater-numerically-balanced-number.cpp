class Solution {
public:
    bool solve(int i){
        map<int,int> mp;
        while(i>0){
            int rem=i%10;
            mp[rem]++;
            i=i/10;
        }
        for(auto it: mp){
            if(it.first!=it.second) return false;
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        int i=n+1;
        while(true){
            if(solve(i)) return i;
            i=i+1;
        }
        return -1;
    }
};
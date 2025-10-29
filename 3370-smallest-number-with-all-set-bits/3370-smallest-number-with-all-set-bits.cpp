class Solution {
public:
    int smallestNumber(int n) {
        int ans=0;
        for(int i=0;i<32;i++) {
            if(ans>=n) break;
            ans=ans|(1<<i);
        }
        return ans;
        
    }
};
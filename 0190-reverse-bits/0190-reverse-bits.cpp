class Solution {
public:
    int reverseBits(int n) {
        int ans=0;
        int val=31;
        for(int i=0;i<31;i++){
            int bit=(n>>i) & 1;
            bit=(bit<<(val-i));
            ans=ans|bit;
        }
        return ans;
    }
};
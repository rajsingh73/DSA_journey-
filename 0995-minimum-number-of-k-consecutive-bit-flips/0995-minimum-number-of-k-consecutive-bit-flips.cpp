class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> flipstore(n,0);
        int ans=0;
        int flipcount=0;
        for(int i=0;i<n;i++){
            if(i-k>=0){
                flipcount=flipcount-flipstore[i-k];
            }
            if(nums[i]==0){
                if(flipcount%2==0){
                    if(i+k>n) return -1;
                    flipstore[i]=1;
                    flipcount++;
                    ans++;
                }
                else continue;
            }
            else{
                if(flipcount%2==1){
                    if(i+k>n) return -1;
                    flipstore[i]=1;
                    flipcount++;
                    ans++;
                }
                else continue;
            }
        }
        return ans;
    }
};
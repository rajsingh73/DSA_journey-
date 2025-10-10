class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        map<int,int> mp;
        for(int i=0;i<energy.size();i++){
            if(i-k>=0){
                int rem=i%k;
                mp[rem]=max(mp[rem]+energy[i],energy[i]);
            }
            else mp[i]=energy[i];
        }
        int ans=INT_MIN;
        for(auto it: mp){
            ans=max(ans,it.second);
        }
        return ans;
    }
};
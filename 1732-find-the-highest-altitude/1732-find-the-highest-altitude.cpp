class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0;
        int alti=gain[0];
        for(int i=1;i<gain.size();i++){
            ans=max(ans,alti);
            alti+=gain[i];
        }
        ans=max(ans,alti);
        return ans; 
    }
};
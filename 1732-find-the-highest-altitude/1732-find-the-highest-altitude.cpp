class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0;
        int alti=0;
        for(int i=0;i<gain.size();i++){
            alti+=gain[i];
            ans=max(ans,alti);
        }
        return ans; 
    }
};
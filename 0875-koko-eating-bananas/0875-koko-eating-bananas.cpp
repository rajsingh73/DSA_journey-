class Solution {
public:
    bool solve(vector<int> & piles,int h,int value){
        int ans=0;
        for(auto it: piles){
            if(it%value==0) ans+=(it/value);
            else ans+=(it/value)+1;
        }
        return ans<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=0;
        for(auto it: piles) maxi=max(maxi,it);
        int low=1;
        int high=maxi;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(solve(piles,h,mid)) high=mid-1;
            else low=mid+1;
            cout<<mid<<" ";
        }
        return low;
    }
};
class Solution {
public:
    bool check(vector<long long> def,long long mid,int r,int k){
        long long cumi=0;
        int n=def.size();
        for(int i=0;i<n;i++){
            cumi+=def[i];
            if(cumi<mid){
                long long needed=mid-cumi;
                if(needed>k) return false;
                k-=needed;
                cumi+=needed;
                if(2*r+1+i<n) def[2*r+1+i]-=needed;
            }
        }
        return true;
    }
    long long maxPower(vector<int>& stations, int r, int k) {
        int n=stations.size();
        long long low=*min_element(stations.begin(),stations.end());
        long long high=accumulate(stations.begin(),stations.end(),0LL)+k;
        long long result=0;
        vector<long long> def(n,0);
        for(int i=0;i<n;i++){
            def[max(0,i-r)]+=stations[i];
            if(i+r+1<n) def[i+r+1]-=stations[i];
        }
        for(auto it: def)cout<<it<<" ";
        while(low<=high){
            long long mid=low+((high-low)/2);
            if(check(def,mid,r,k)){
                low=mid+1;
                result=mid;
            }
            else{
                high=mid-1;
            }
        }
        return result;
    }
};
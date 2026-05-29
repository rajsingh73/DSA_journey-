class Solution {
public:
    int maximumRobots(vector<int>& chargetimes, vector<int>& runningcosts, long long budget) {
        int i=0;
        int ans=0;
        int j=0;
        int n=chargetimes.size();
        int maxicharg=chargetimes[0];
        long long sumrun=runningcosts[0];
        while(j<n){
            long long eq=maxicharg+(j-i+1)*sumrun;
            if(eq>budget){
                if(i==j){
                    j++;
                    i++;
                    if(j == n) break;
                    maxicharg=chargetimes[j];
                    sumrun=runningcosts[j];
                }
                else{
                    int maxi=0;
                    for(int k=i+1;k<=j;k++){
                        maxi=max(chargetimes[k],maxi);
                    }
                    maxicharg=maxi;
                    sumrun-=runningcosts[i];
                    i++;
                }
            }
            else{
                ans=max(ans,j-i+1);
                j++;
                if(j<n){
                    maxicharg=max(maxicharg,chargetimes[j]);
                    sumrun+=runningcosts[j];
                    // j++;
                }
            }
        }
        // cout<<i<<" "<<j;
        // long long eq=maxicharg+(j-i+1)*sumrun;
        // if(eq <= budget) ans = max(ans, j-i+1);
        // return max(ans, j-i + 1);
        return ans;

    }
};
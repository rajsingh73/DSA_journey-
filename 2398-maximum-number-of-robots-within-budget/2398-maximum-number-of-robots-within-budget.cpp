class Solution {
public:
    int maximumRobots(vector<int>& chargetimes, vector<int>& runningcosts, long long budget) {
        long long l=0,sum=0,n=chargetimes.size();
        multiset<int> s;
        int i=0;
        for(int j=0;j<n;j++){
            sum+=runningcosts[j];
            s.insert(chargetimes[j]);
            if(*rbegin(s)+sum*(j-i+1)>budget){
                sum-=runningcosts[i];
                s.erase(s.find(chargetimes[i]));
                i++;
            }
        }
        return n-i;
    }
};
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans=0;
        int i=1;
        while(i<colors.size()){
            if(colors[i]!=colors[i-1]) i++;
            else{
                int great=neededTime[i-1];
                int sum=neededTime[i-1];
                while(colors[i]==colors[i-1] && i<colors.size()){
                    great=max(great,neededTime[i]);
                    sum+=neededTime[i];
                    i++;
                }
                cout<<sum<<" "<<great<<endl;
                sum-=great;
                ans+=sum;
            }
        }
        return ans;
    }
};
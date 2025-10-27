class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        int m=bank[0].size();
        int ans=0;
        int count=0;
        for(int i=0;i<n;i++){
            int cs=0;
            for(int j=0;j<m;j++){
                if(bank[i][j]=='1') cs++;
            }
            ans+=(count*cs);
            if(cs!=0)count=cs;
        }
        return ans;
        
    }
};
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
        for(int i=1;i<=n;i++){
            if(ans.size()==n+1) break;
            int count=1;
            for(int j=0;j<i;j++) {
                if(ans.size()==n+1) break;
                ans.push_back(count);
                count++;
            }
        }
        return ans;
    }
};
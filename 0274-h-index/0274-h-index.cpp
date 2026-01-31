class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int n=citations.size();
        for(int i=n;i>0;i--){
            int newi=n-i;
            if(citations[newi]>=i) return i;
        }
        return 0;
    }
};
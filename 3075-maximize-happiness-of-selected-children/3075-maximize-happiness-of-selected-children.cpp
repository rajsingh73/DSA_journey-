class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(),happiness.rend());
        int n=happiness.size();
        long long total=0;
        int index=0;
        while(index<n && k>0 && happiness[index]-index>0){
            total+=happiness[index]-index;
            index++;
            k--;
        }
        return total;
    }
};
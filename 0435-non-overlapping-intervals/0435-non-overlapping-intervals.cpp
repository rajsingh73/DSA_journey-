class Solution {
public:
    static bool comp(vector<int> first,vector<int> second){
        return first[1]<second[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end(),comp);
        int count=0;
        int second=arr[0][1];
        int i=1;
        while(i<arr.size()){
            if(second>arr[i][0]){
                count++;
                i++;
                continue;
            }
            second=arr[i][1];
            i++;
        }
        return count;
    }
};
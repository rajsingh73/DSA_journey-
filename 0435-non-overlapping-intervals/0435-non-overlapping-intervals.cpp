class Solution {
public:
    static bool comp(vector<int> first,vector<int> second){
        return first[1]<second[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int n=intervals.size();
        int i=0;
        int count=0;
        while(i<n){
            int second=intervals[i][1];
            i++;
            while(i<n && intervals[i][0]<second){
                count++;
                i++;
            }
        }
        return count;
        
    }
};
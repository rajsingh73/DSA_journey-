class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int i=0;
        while(i<intervals.size()){
            int first=intervals[i][0];
            int second=intervals[i][1];
            while(i<intervals.size()-1 && intervals[i+1][0]<=intervals[i][1]){
                i++;
                second=max(second,intervals[i][1]);
            }
            ans.push_back({first,second});
            i++;
        }
        return ans;
        
    }
};
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        int i=0;
        vector<vector<int>> ans;
        while(i<n && intervals[i][1]<newInterval[0]){
            ans.push_back({intervals[i][0],intervals[i][1]});
            i++;
        }
        int start=min(newInterval[0],intervals[i][0]);
        int end=newInterval[1];
        while(i<n && end>=intervals[i][0]){
            end=max(end,intervals[i][1]);
            i++;
        }
        ans.push_back({start,end});
        while(i<n){
            ans.push_back({intervals[i][0],intervals[i][1]});
            i++;
        }
        return ans;


        
    }
};
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int count=0;
        int n=points.size();
        int i=0;
        while(i<n){
            int second=points[i][1];
            i++;
            count++;
            while(i<n && points[i][0]<=second){
                second=min(second,points[i][1]);
                i++;
            }
        }
        return count;
    }
};
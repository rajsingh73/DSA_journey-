class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<points.size();i++){
            int dist=pow(points[i][0],2)+pow(points[i][1],2);
            pq.push({dist,i});
            if(pq.size()>k) pq.pop();
        }
        vector<vector<int>> ans;
        while(pq.size()){
            int i=pq.top().second;
            ans.push_back(points[i]);
            pq.pop();
        }
        return ans;
        
    }
};
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int,int>>,vector<pair<int, pair<int,int>>>,greater<pair<int, pair<int,int>>>> pq;
        int ans=INT_MAX;
        pq.push({0,{0,0}});
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> distance(n,vector<int>(m,INT_MAX));
        distance[0][0]=0;
        vector<int> rc={1,0,-1,0};
        vector<int> cc={0,1,0,-1};
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            int diff=p.first;
            int row=p.second.first;
            int col=p.second.second;
            if(row==n-1 && col==m-1) return diff;
            for(int i=0;i<4;i++){
                int nrow=row+rc[i];
                int ncol=col+cc[i];
                if(nrow>-1 && nrow<n && ncol>-1 && ncol<m && max(diff,abs(heights[row][col]-heights[nrow][ncol]))<distance[nrow][ncol]){
                    distance[nrow][ncol]=max(diff,abs(heights[row][col]-heights[nrow][ncol]));
                    pq.push({distance[nrow][ncol],{nrow,ncol}});
                }
            }
        }
        return -1;

    }
};
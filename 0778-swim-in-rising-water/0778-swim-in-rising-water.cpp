class Solution {
public:
    bool isvalid(int n, int row,int col){
        return row>=0 && row<n && col<n && col>=0;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int ans=INT_MIN;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0],{0,0}});
        int n=grid.size();
        vector<vector<int>> visited(n,vector<int> (n,0));
        visited[0][0]=1;
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            int row=p.second.first;
            int col=p.second.second;
            int value=p.first;
            ans=max(ans,value);
            if(row==n-1 && col==n-1) return ans;
            int dr[4]={-1,0,1,0};
            int dc[4]={0,-1,0,1};
            for(int i=0;i<4;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                if(isvalid(n,nrow,ncol) && visited[nrow][ncol]==0){
                    int val=max(ans,grid[nrow][ncol]);
                    visited[nrow][ncol]=1;
                    pq.push({val,{nrow,ncol}});
                }
            }
        }
        return ans;
        
    }
};
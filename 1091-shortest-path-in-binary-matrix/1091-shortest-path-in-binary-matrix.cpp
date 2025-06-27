class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        priority_queue<pair<int, pair<int,int>>,vector<pair<int, pair<int,int>>>,greater<pair<int, pair<int,int>>>> pq;
        pq.push({1,{0,0}});
        vector<vector<int>> distance(n,vector<int>(n,INT_MAX));
        distance[0][0]=1;
        while(!pq.empty()){
            pair<int,pair<int,int>> p=pq.top();
            pq.pop();
            int value=p.first;
            int i=p.second.first;
            int j=p.second.second;
            for(int k=-1;k<=1;k++){
                for(int l=-1;l<=1;l++){
                    if(k==0 && l==0) continue;
                    int first=i+k;
                    int second=j+l;
                    if(first>=0 && first<n && second>=0 && second<n && grid[first][second]!=1 && distance[first][second]>value+1){
                        distance[first][second]=value+1;
                        pq.push({value+1,{first,second}});
                    }
                }
            }
        }
        return distance[n-1][n-1]==INT_MAX?-1:distance[n-1][n-1];


        
    }
};
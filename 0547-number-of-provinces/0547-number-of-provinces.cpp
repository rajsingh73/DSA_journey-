class Solution {
public:
    void solve(vector<vector<int>>& adj,vector<int> & visited,int root){
        if(visited[root]) return;
        visited[root]=1;
        for(auto it: adj[root]){
            solve(adj,visited,it);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> visited(isConnected.size(),0);
        vector<vector<int>> adj(isConnected.size());
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[i].size();j++){
                if(isConnected[i][j]==1 && i!=j) adj[i].push_back(j);
            }
        }
        int ans=0;
        for(int i=0;i<isConnected.size();i++){
            if(visited[i]!=1){
                solve(adj,visited,i);
                ans++;
            }
        }
        return ans;
    }
};
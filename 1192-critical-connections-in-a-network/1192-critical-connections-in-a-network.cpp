class Solution {
public:
    int timer=1;
    void dfs(int node,vector<vector<int>> & adj,vector<int> & tim,vector<int> & low,vector<int> & visited,vector<vector<int>> & bridges,int parent){
        visited[node]=1;
        tim[node]=low[node]=timer;
        timer++;
        for(auto it : adj[node]){
            if(parent==it) continue;
            if(visited[it]==0){
                dfs(it,adj,tim,low,visited,bridges,node);
                low[node]=min(low[node],low[it]);
                if(tim[node]<low[it]){
                    bridges.push_back({node,it});
                }
            }
            else{
                low[node]=min(low[node],low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto it: connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> tim(n);
        vector<int> low(n);
        vector<vector<int>> bridges;
        vector<int> visited(n,0);
        dfs(0,adj,tim,low,visited,bridges,-1);
        return bridges;
    }
};
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back({connections[i][1],1});
            adj[connections[i][1]].push_back({connections[i][0],0});
        }
        queue<int> q;
        q.push(0);
        vector<int> visited(n);
        int res=0;
        visited[0]=1;
        while(!q.empty()){
            int val=q.front(); q.pop();
            for(auto it: adj[val]){
                if(visited[it.first]==0){
                    if(it.second==1) res++;
                    q.push(it.first);
                    visited[it.first]=1;
                }
            }
        }
        return res;
    }
};
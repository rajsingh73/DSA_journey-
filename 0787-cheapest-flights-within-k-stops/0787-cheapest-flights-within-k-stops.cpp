class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto& it : flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        queue<tuple<int, int, int>> q; 
        q.push({0, src, 0});
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        while(!q.empty()){
            auto [stops, node, cost] = q.front();
            q.pop();
            if(stops > k) continue;
            for(auto& it : adj[node]){
                int neigh = it.first;
                int price = it.second;
                if(cost + price < dist[neigh]){
                    dist[neigh] = cost + price;
                    q.push({stops + 1, neigh, dist[neigh]});
                }
            }
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};

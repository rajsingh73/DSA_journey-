class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        map<int, vector<pair<int, int>>> mp;
        for (auto it : roads) {
            mp[it[0]].push_back({it[1], it[2]});
            mp[it[1]].push_back({it[0], it[2]});
        }

        vector<long long> dist(n, LLONG_MAX);  // Use long long
        vector<int> way(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

        pq.push({0, 0});
        dist[0] = 0;
        way[0] = 1;

        while (!pq.empty()) {
            auto [distance, node] = pq.top();
            pq.pop();

            if (distance > dist[node]) continue;

            for (auto& it : mp[node]) {
                int noded = it.first;
                int value = it.second;

                if (distance + value < dist[noded]) {
                    dist[noded] = distance + value;
                    way[noded] = way[node];
                    pq.push({dist[noded], noded});
                }
                else if (distance + value == dist[noded]) {
                    way[noded] = (way[noded] + way[node]) % MOD;
                }
            }
        }

        return way[n - 1];
    }
};

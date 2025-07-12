class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        map<int,vector<pair<int,int>>> mp;
        for( auto it : times) mp[it[0]].push_back({it[1],it[2]});
        queue<pair<int,int>> q;
        vector<int> distance(n+1,INT_MAX);
        distance[k]=1;
        q.push({0,k});
        while(!q.empty()){
            auto [dist,node] = q.front();
            q.pop();
            for(auto it : mp[node]){
                int value=it.second;
                int noded=it.first;
                if(dist+value<distance[noded]){
                    distance[noded]=dist+value;
                    q.push({dist+value,noded});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<n+1;i++){
            if(distance[i]==INT_MAX) return -1;
            ans=max(ans,distance[i]);
        }
        return ans;

        
    }
};
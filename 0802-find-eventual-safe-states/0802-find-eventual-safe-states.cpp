class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>> adj(graph.size());
        vector<int> indegree(graph.size(),0);
        for(int i=0;i<graph.size();i++){
            for(int it:graph[i]){
                adj[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        vector<int> ans;
        for(int i=0;i<graph.size();i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                int popet=q.front();
                q.pop();
                for(int it:adj[popet]){
                    indegree[it]--;
                    if(indegree[it]==0) q.push(it);
                }
                ans.push_back(popet);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};
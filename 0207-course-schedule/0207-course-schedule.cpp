class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        for(auto it:prerequisites){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        queue<int> q;
        vector<int> ans;
        for(int i=0;i<n;i++){
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
        if(ans.size()==n) return true;
        return false;
        
    }
};
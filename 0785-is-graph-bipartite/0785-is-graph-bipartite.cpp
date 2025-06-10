class Solution {
public:
    bool dfs(vector<vector<int>> & graph,vector<int> & visited,int start,bool val){
        bool ans=true;
        for(int it:graph[start]){
            if(visited[it]!=-1){
                if(visited[it]==val) return false;
            }
            else{
                visited[it]=!val;
                ans=ans&&dfs(graph,visited,it,!val);
            }
        }
        return ans;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> visited(n,-1);
        bool ans=true;
        for(int i=0;i<n;i++){
            if(visited[i]==-1){
                visited[i]=0;
                ans=ans&& dfs(graph,visited,i,0);
            }
        }
        return ans;
        
    }
};
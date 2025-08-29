class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int> visited(n,0);
        visited[0]=1;
        queue<int> q;
        q.push(0);
        while(q.size()){
            int nextroom=q.front(); q.pop();
            for(auto it: rooms[nextroom]){
                if(visited[it]==0) {
                    q.push(it);
                    visited[it]=1;
                }
            }
        }
        for(auto it: visited){
            if(it==0) return false;
        }
        return true; 
    }
};
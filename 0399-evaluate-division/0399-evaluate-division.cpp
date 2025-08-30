class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string,vector<pair<string,double>>> mp;
        for(int i=0;i<equations.size();i++){
            mp[equations[i][0]].push_back({equations[i][1],values[i]});
            mp[equations[i][1]].push_back({equations[i][0],1.0/values[i]});
        }
        vector<double> ans;
        for(int i=0;i<queries.size();i++){
            string src=queries[i][0];
            string dep=queries[i][1];
            if( !mp.count(src) || !mp.count(dep)){
                ans.push_back(-1);
                continue;
            }
            if(src==dep){
                ans.push_back(1);
                continue;
            }
            queue<pair<string,double>> q;
            set<string> vis;
            q.push({src,1});
            vis.insert(src);
            double res=-1;
            while(!q.empty()){
                auto [node,val] =q.front(); q.pop();
                if(node==dep){
                    res=val;
                    break;
                }
                for(auto [nei,weight]:mp[node]){
                    if(!vis.count(nei)){
                        q.push({nei,val*weight});
                        vis.insert(nei);
                    }
                }
            }
            ans.push_back(res);
        }
        return ans;
    }
};
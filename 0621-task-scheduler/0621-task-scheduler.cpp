class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int> mp;
        for(auto it: tasks) mp[it]++;
        priority_queue<int> pq;
        for(auto it: mp) pq.push(it.second);
        int time=0;
        while(pq.size()){
            vector<int> temp;
            for(int i=0;i<=n;i++){
                if(pq.size()){
                    int freq=pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }
            for(auto it: temp){
                if(it!=0) pq.push(it);
            }
            if(pq.empty()){
                time+=temp.size();
            }
            else time+=n+1;
        }
        return time;
        
    }
};
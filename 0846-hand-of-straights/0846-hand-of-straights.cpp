class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0) return false;
        map<int,int> mp;
        for(auto it: hand) mp[it]++;
        priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<pair<int,int>>> pq;
        for(auto it: mp) pq.push({it.first,it.second});
        for(int i=0;i<hand.size()/groupSize;i++){
            vector<pair<int,int>> temp;
            for(int j=0;j<groupSize;j++){
                if(pq.empty()) return false;
                if(j!=0){
                    if(temp[temp.size()-1].first!=pq.top().first-1) return false;
                    int first=pq.top().first;
                    int second=pq.top().second-1;
                    temp.push_back({first,second});
                    pq.pop();
                }
                else{
                    int first=pq.top().first;
                    int second=pq.top().second-1;
                    temp.push_back({first,second});
                    pq.pop();
                }
            }
            for(auto it: temp) {
                if(it.second!=0) pq.push(it);
            }
        }
        return true;
        
    }
}; 
class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>> pq;
        map<char,int> mp;
        for(auto it: s) mp[it]++;
        for(auto it: mp) pq.push({it.second,it.first});
        string ans="";
        while(pq.size()){
            vector<char> temp;
            int freq=pq.top().first;
            char c=pq.top().second;
            temp.push_back(c);
            pq.pop();
            while(pq.size() && pq.top().first==freq){
                temp.push_back(pq.top().second);
                pq.pop();
            }
            for(int i=temp.size()-1;i>=0;i--){
                for(int j=0;j<freq;j++) ans+=temp[i];
            }
        }
        return ans;
        
    }
};
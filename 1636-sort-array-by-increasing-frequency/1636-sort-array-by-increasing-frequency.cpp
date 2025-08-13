class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> mp;
        for(auto it:nums) mp[it]++;
        priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>>> pq;
        for(auto it : mp){
            pq.push({it.second,it.first});
        }
        vector<int> ans;
        while(pq.size()){ 
            vector<pair<int,int>> temp;
            int val=pq.top().first;
            int mat=pq.top().second;
            temp.push_back({val,mat});
            pq.pop();
            while(pq.size() && pq.top().first==val){
                temp.push_back({pq.top().first,pq.top().second});
                pq.pop();
            }
            for(int i=temp.size()-1;i>=0;i--){
                int vall=temp[i].first;
                for(int j=0;j<vall;j++){
                    ans.push_back(temp[i].second);
                }
            }

        }
        return ans;
        
    }
};
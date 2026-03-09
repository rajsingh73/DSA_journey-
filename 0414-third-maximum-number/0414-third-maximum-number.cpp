class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>> pq;
        map<int,int> mp;
        int maxi=INT_MIN;
        for(auto it: nums){
            if(mp.find(it)==mp.end()){
                pq.push(it);
                if(pq.size()>3) pq.pop();
                mp[it]++;
                maxi=max(maxi,it);
            }
        }
        return pq.size()==3?pq.top():maxi;

    }
};
class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        map<int,int> mp;
        int i=0;
        int j=0;
        while(j-i+1<=k){
            mp[nums[j]]++;
            j++;
        }
        j--;
        vector<int> ans;
        while(j<nums.size()){
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
            for(auto it: mp){
                pq.push({it.second,it.first});
                if(pq.size()>x) pq.pop();
            }
            int sum=0;
            while(pq.size()){
                auto p=pq.top(); pq.pop();
                int mul=p.first;
                int val=p.second;
                sum+=(mul*val);
            }
            ans.push_back(sum);
            mp[nums[i]]--;
            if(mp[nums[i]]==0) mp.erase(nums[i]);
            i++;
            j++;
            if(j<nums.size()) mp[nums[j]]++;
        }
        return ans;
    }
};
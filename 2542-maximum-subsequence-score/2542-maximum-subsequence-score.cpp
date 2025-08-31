class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> temp;
        for(int i=0;i<nums1.size();i++){
            temp.push_back({nums2[i],nums1[i]});
        }
        sort(temp.rbegin(),temp.rend());
        priority_queue<int,vector<int>,greater<int>> pq;
        long long sum=0;
        long long ans=0;
        for(auto p:temp){
            int first=p.first;
            int second=p.second;
            sum+=second;
            pq.push(second);
            if(pq.size()>k) {
                sum-=pq.top();
                pq.pop();
            }
            if(pq.size()==k) ans=max(ans,sum*1LL*first);
        }
        return ans;
    }
};
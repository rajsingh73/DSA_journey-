class Solution {
public:
    void solve(vector<int> & nums,vector<vector<int>> & ans,vector<int> v,vector<int> visited,int n){
        if(v.size()==n){
            ans.push_back(v);
            return;
        }
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1] && visited[i-1]==0) continue;
            if(visited[i]==0){
                v.push_back(nums[i]);
                visited[i]=1;
                solve(nums,ans,v,visited,n);
                v.pop_back();
                visited[i]=0;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> visited(n,0);
        vector<vector<int>> ans;
        vector<int> v;
        solve(nums,ans,v,visited,n);
        return ans;
        
    }
};
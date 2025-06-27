class Solution {
public:
    void solve(vector<int> & nums,vector<vector<int>> & ans,vector<int> v,vector<int> visited,int n){
        if(v.size()==n){
            ans.push_back(v);
            return;
        }
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                v.push_back(nums[i]);
                visited[i]=1;
                solve(nums,ans,v,visited,n);
                v.pop_back();
                visited[i]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int> visited(n,0);
        vector<vector<int>> ans;
        vector<int> v;
        solve(nums,ans,v,visited,n);
        return ans;
        
    }
};
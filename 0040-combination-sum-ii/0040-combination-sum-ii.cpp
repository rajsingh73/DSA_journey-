class Solution {
public:
    void solve(vector<int> &candidates,int target,int index,vector<vector<int>> &ans,vector<int> temp){
        if(index==candidates.size()){
            if(target==0){
                ans.push_back(temp);
            }
            return;
        }
        if(target>=candidates[index]){
            temp.push_back(candidates[index]);
            solve(candidates,target-candidates[index],index+1,ans,temp);
            temp.pop_back();
        }
        while(index+1<candidates.size() && candidates[index]==candidates[index+1]) index++;
        solve(candidates,target,index+1,ans,temp);

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>  ans;
        vector<int> temp;
        solve(candidates,target,0,ans,temp);
        return ans;
        
    }
};
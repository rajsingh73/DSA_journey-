class Solution {
public:
    void solve(int k,int n,vector<vector<int>> &ans,vector<int> temp,int val,int sum){
        if(temp.size()==k){
            if(sum==n) ans.push_back(temp);
            return;
        }
        for(int i=val;i<=9;i++){
            if(sum>n) break;
            temp.push_back(i);
            solve(k,n,ans,temp,i+1,sum+i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(k,n,ans,temp,1,0);
        return ans;
    }
};
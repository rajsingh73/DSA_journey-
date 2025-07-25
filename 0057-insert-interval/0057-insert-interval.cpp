class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& arr, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i=0;
        int n=arr.size();
        while(i<n && newInterval[0]>arr[i][1]){
            ans.push_back({arr[i][0],arr[i][1]});
            i++;
        }
        int first=newInterval[0];
        int second=newInterval[1];
        while(i<n && arr[i][0]<=second){
            second=max(second,arr[i][1]);
            first=min(first,arr[i][0]);
            i++;
        }
        ans.push_back({first,second});
        while(i<n){
            ans.push_back({arr[i][0],arr[i][1]});
            i++;
        }
        return ans;
        
    }
};
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        int i=0;
        while(i<arr.size()){
            int start=arr[i][0];
            int end=arr[i][1];
            i++;
            while(i<arr.size() && end>=arr[i][0]){
                end=max(end,arr[i][1]);
                i++;
            }
            ans.push_back({start,end});
        }
        return ans;
        
    }
};
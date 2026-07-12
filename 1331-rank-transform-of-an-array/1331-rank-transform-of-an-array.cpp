class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<pair<int,int>> v;
        for(int i=0;i<arr.size();i++){
            v.push_back({arr[i],i});
        }
        int c=0;
        sort(v.begin(),v.end());
        for(int i=0;i<arr.size();i++){
            if(i>0 && v[i].first==v[i-1].first){
                arr[v[i].second]=c;
            }
            else{
                c++;
                arr[v[i].second]=c;
            }

        }
        return arr;
        
    }
};
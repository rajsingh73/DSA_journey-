class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int,int> mp;
        for(auto it: arr) mp[it]++;
        for(auto it:arr){
            if(it==0){
                if(mp.find(it)!=mp.end()){
                    if(mp[it]>1) return true;
                }
            }
            else if(mp.find(2*it)!=mp.end()) return true;
        }
        return false;
        
    }
};
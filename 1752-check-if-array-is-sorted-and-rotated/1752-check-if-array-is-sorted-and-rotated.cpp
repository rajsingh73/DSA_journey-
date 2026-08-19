class Solution {
public:
    bool check(vector<int>& arr) {
        int check=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>arr[(i+1)%arr.size()]) check++;
        }
        if(check==0 || check==1) return true;
        else return false;

        
    }
};
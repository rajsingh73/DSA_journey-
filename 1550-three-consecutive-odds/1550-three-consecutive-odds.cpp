class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int i=0;
        int count=0;
        while(i<arr.size()){
            if(arr[i]%2!=0) count++;
            else{
                count=0;
            }
            if(count==3) return true;
            i++;
        }
        return false;
    }
};
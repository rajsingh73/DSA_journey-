class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int num=INT_MAX;
        for(auto it:nums){
            if(count==0){
                num=it;
                count++;
            }
            else if(num==it) count++;
            else{
                count--;
            }
        }
        return num;
    }
};
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element=-1;
        int count=0;
        for(auto it: nums){
            if(element==it) count++;
            else if(count==0){
                element=it;
                count=1;
            }
            else{
                count--;
                if(count==0){
                    element=it;
                    count++;
                }
            }
        }
        return element;
        
    }
};
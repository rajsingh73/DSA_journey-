class Solution {
public:
    string largestOddNumber(string nums) {
        int i=nums.size()-1;
        while(i>=0){
            int val=nums[i]-'0';
            if(val%2!=0) break;
            i--;
        }
        if(i<0) return "";
        return nums.substr(0,i+1);
    }
};
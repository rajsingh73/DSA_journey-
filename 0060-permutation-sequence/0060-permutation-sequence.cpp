class Solution {
public:
    void nextPermutation(string & nums) {
        int index=-1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                index=i;
                break;
            }
        }
        if(index==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=nums.size()-1;i>index;i--){
            if(nums[i]>nums[index]){
                swap(nums[i],nums[index]);
                break;
            }
        }
        reverse(nums.begin()+index+1,nums.end());
    }
    string getPermutation(int n, int k) {
        string s="";
        int count=1;
        for(int i=0;i<n;i++){
            s.push_back(char(count+'0'));
            count++;
        }
        for(int i=0;i<k-1;i++){
            nextPermutation(s);
        }
        return s;
    }
};
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n =nums.size();
        int rotated=k%n;
        if(rotated==0) return;
        reverse(nums.begin(),nums.begin()+n-rotated);
        reverse(nums.begin()+n-rotated,nums.end());
        reverse(nums.begin(),nums.end());
    }
};
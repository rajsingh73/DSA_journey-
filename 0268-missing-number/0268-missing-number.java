class Solution {
    public int missingNumber(int[] nums) {
        int n=nums.length;
        int sum=(n*(n+1))/2;
        int arrsum=0;
        for(int it:nums) arrsum+=it;
        return sum-arrsum;
    }
}
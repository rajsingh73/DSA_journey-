class Solution {
public:
    string triangleType(vector<int>& nums) {
        int first=nums[0];
        int second=nums[1];
        int third=nums[2];
        if(first>second+third || second>first+third || third>first+second) return "none";
        if(first==second && second==third) return "equilateral";
        if(first==second || second==third || third==first) return "isosceles";
        if(first!=second && second!=third && third!=first) return "scalene";
        return "none";
    }
};
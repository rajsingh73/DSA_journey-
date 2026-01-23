class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left=m-1;
        int right=n-1;
        int total=m+n-1;
        while(left>=0 || right>=0){
            if(left>=0 && right>=0){
                if(nums1[left]>nums2[right]) nums1[total--]=nums1[left--];
                else nums1[total--]=nums2[right--];
            }
            else if(left>=0) nums1[total--]=nums1[left--];
            else nums1[total--]=nums2[right--];
        }
        
    }
};
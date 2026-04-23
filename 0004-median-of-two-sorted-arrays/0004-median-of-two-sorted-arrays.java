class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int i=0;
        int half=(nums1.length+nums2.length)/2;
        int l=0,r=0,first=0,second=0;
        while(i<=half){
            second=first;
            if( (l < nums1.length && (r >= nums2.length || nums1[l] <= nums2[r]))){
                first=nums1[l];
                l++;
            }
            else{
                first=nums2[r];
                r++;
            }
            i++;
        }
        if((nums1.length+nums2.length)%2==0) return (first+second)/2.0;
        else return first;
        
    }
}
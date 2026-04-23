class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int i=0;
        int half=(nums1.length+nums2.length)/2;
        int l=0,r=0,first=0,second=0;
        while(i<=half){
            if((r>=nums2.length)){
                second=first;
                first=nums1[l];
                l++;
            }
            else if(l>=nums1.length){
                second=first;
                first=nums2[r];
                r++;
            }
            else if(nums1[l]<=nums2[r]){
                second=first;
                first=nums1[l];
                l++;
            }
            else{
                second=first;
                first=nums2[r];
                r++;
            }
            i++;
        }
        if((nums1.length+nums2.length)%2==0) return (first+second)/2.0;
        else return first;
    }
}
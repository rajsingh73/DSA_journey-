class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0;
        int half=(nums1.size()+nums2.size())/2;
        int first=0;
        int second=0;
        int l=0;
        int r=0;
        while(i<=half){
            if(r>=nums2.size()){
                second=first;
                first=nums1[l];
                l++;
            }
            else if(l>=nums1.size()){
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
        if((nums1.size()+nums2.size())%2==0) return (first+second)/2.0;
        else return first;
    }
};
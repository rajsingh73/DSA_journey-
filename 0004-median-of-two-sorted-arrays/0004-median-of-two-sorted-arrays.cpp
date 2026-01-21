class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double first=-1;
        double second=-1;
        int count=0;
        int i=0;
        int j=0;
        int total=nums1.size()+nums2.size();
        if(total==1){
            return nums1.size()?nums1[0]:nums2[0];
        }
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j]){
                if(first==-1) first=nums1[i];
                else if(second==-1) second=nums1[i];
                else{
                    first=second;
                    second=nums1[i];
                }
                i++;
            }
            else{
                if(first==-1) first=nums2[j];
                else if(second==-1) second=nums2[j];
                else{
                    first=second;
                    second=nums2[j];
                }
                j++;
            }
            count++;
            if(count==(total/2)+1){
                return total%2==0?(first+second)/2.0:second;
            }

        }
        while(i<nums1.size()){
            if(first==-1) first=nums1[i];
            else if(second==-1) second=nums1[i];
            else{
                first=second;
                second=nums1[i];
            }
            count++;
            if(count==(total/2)+1){
                return total%2==0?(first+second)/2.0:second;
            }
            i++;
        }
        while(j<nums2.size()){
            cout<<"HELLO";
            if(first==-1) first=nums2[j];
            else if(second==-1) second=nums2[j];
            else{
                first=second;
                second=nums2[j];
            }
            count++;
            if(count==(total/2)+1){
                return total%2==0?(first+second)/2.0:second;
            }
            j++;
        }
        return first;
    }
};
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int i=0;
        int j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }
            else{
                ans.push_back(nums2[j]);
                j++;
            }
        }
        while(i<nums1.size()){
            ans.push_back(nums1[i]);
            i++;
        }
        while(j<nums2.size()){
            ans.push_back(nums2[j]);
            j++;
        }
        int m=ans.size()/2;
        if(ans.size()%2==0){
            return (ans[m]+ans[m-1])/2.0;
        }
        else{
            return ans[m];
        }
    }
};
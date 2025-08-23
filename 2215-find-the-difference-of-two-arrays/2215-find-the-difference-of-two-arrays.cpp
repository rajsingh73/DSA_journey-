class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=0;
        int j=0;
        vector<int> first;
        vector<int> second;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]==nums2[j]){
                int temp=nums1[i];
                while(i<nums1.size() && nums1[i]==temp) i++;
                temp=nums2[j];
                while(j<nums2.size() && nums2[j]==temp) j++;
            }
            else if(nums1[i]<nums2[j]){
                int temp=nums1[i];
                while(i<nums1.size() && nums1[i]==temp) i++;
                first.push_back(temp);
            }
            else{
                int temp=nums2[j];
                while(j<nums2.size() && nums2[j]==temp) j++;
                second.push_back(temp);
            }
        }
        while(i<nums1.size()){
            int temp=nums1[i];
            while(i<nums1.size() && nums1[i]==temp) i++;
            first.push_back(temp);
        }
        while(j<nums2.size()){
            int temp=nums2[j];
            while(j<nums2.size() && nums2[j]==temp) j++;
            second.push_back(temp);
        }
        return {first,second};
        
    }
};
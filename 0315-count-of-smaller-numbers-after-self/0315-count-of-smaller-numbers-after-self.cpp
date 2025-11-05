class Solution {
public:
    void merge(vector<pair<int,int>> & nums,vector<int> & ans,int low,int mid,int high){
        vector<pair<int,int>> v;
        int l=low;
        int h=mid+1;
        while(l<=mid && h<=high){
            if(nums[l].first>nums[h].first){
                ans[nums[l].second]+=(high-h+1);
                v.push_back(nums[l]);
                l++;
            }
            else{
                v.push_back(nums[h]);
                h++;
            }
        }
        while(l<=mid){
            v.push_back(nums[l]);
            l++;
        }
        while(h<=high){
            v.push_back(nums[h]);
            h++;
        }
        for(int i=low;i<=high;i++){
            nums[i]=v[i-low];
        }
    }
    void mergesortlist(vector<pair<int,int>>& nums,vector<int> & ans,int low,int high){
        if(low<high){
            int mid=(low+high)/2;
            mergesortlist(nums,ans,low,mid);
            mergesortlist(nums,ans,mid+1,high);
            merge(nums,ans,low,mid,high); 
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        vector<pair<int,int>> num;
        for(int i=0;i<n;i++){
            num.push_back({nums[i],i});
        }
        mergesortlist(num,ans,0,n-1);
        return ans;
    }
};
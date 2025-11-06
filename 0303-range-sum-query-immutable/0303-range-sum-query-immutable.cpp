class NumArray {
public:
    vector<long long> seg;
    int n=0;
    void build(vector<int> & nums,int low,int high,int index){
        if(low==high){
            seg[index]=nums[low];
            return;
        }
        int mid=(low+high)/2;
        build(nums,low,mid,2*index+1);
        build(nums,mid+1,high,2*index+2);
        seg[index]=seg[2*index+1]+seg[2*index+2];
    }
    int sum(int left,int right,int low,int high,int i){
        if(left>high) return 0;
        if(right<low) return 0;
        if(left<=low && right>=high) return seg[i];
        int mid=(low+high)/2;
        int l=sum(left,right,low,mid,2*i+1);
        int r=sum(left,right,mid+1,high,2*i+2);
        return l+r;
    }
    NumArray(vector<int>& nums) {
        n=nums.size();
        seg.resize(4*n,0);
        build(nums,0,n-1,0);
    }
    int sumRange(int left, int right) {
        return sum(left,right,0,n-1,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
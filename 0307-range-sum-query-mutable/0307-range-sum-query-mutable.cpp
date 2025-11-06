class NumArray {
public:
    vector<long long> seg;
    void builds(vector<int> & nums,long long i,int low,int high){
        if(low==high){
            seg[i]=nums[low];
            return;
        }
        int mid=(low+high)/2;
        builds(nums,2*i+1,low,mid);
        builds(nums,2*i+2,mid+1,high);
        seg[i]=seg[2*i+1]+seg[2*i+2];
    }
    int n=0;
    NumArray(vector<int>& nums) {
        n=nums.size();
        seg.resize(4*n,0);
        builds(nums,0,0,n-1);
    }
    void u(int index,int val,long long i,int low,int high){
        if(low==high){
            seg[i]=val;
            return;
        }
        int mid=low+high/2;
        if(index>=low && index<=mid) u(index,val,2*i+1,low,mid);
        else u(index,val,2*i+2,mid+1,high);
        seg[i]=seg[2*i+1]+seg[2*i+2];
    }
    int su(int left,int right,int low,int high,long long i){
        if(left>high) return 0;
        if(right<low) return 0;
        if(left<=low && right>=high) return seg[i];
        int mid=(low+high)/2;
        int l=su(left,right,low,mid,2*i+1);
        int r=su(left,right,mid+1,high,2*i+2);
        return l+r;
    }
    void update(int index, int val) {
        u(index,val,0,0,n-1);
    }
    int sumRange(int left, int right) {
        return su(left,right,0,n-1,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
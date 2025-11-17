class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int prev=-1;
        int i=0;
        int n=nums.size();
        while(i<n){
            if(nums[i]==1){
                prev=i;
                i++;
                break;
            }
            i++;
        }
        cout<<i<<endl;
        while(i<n){
            if(nums[i]==1){
                int dif=i-prev-1;
                cout<<dif<<" ";
                if(dif<k) return false;
                prev=i;
            }
            i++;
        }
        return true;
        
    }
};
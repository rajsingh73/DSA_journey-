class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> ans;
        int count=1;
        int i=0;
        while(i<n){
            cout<<nums[i]<<" "<<count<<endl;
            if(nums[i]>count){
                while(i<n && nums[i]>count){
                    ans.push_back(count);
                    count++;
                }
            }
            if(i<n){
                int val=nums[i];
                while(i<n && val==nums[i]) i++;
                count++;
            }
        }
        cout<<count;
        while(count<=n){
            ans.push_back(count);
            count++;
        }
        return ans;
    }
};
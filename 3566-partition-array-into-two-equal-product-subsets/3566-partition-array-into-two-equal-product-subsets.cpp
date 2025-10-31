class Solution {
public:
    bool  solve(vector<int>&nums,long long target,int index,vector<int> visited,long long mul){
        if(target<mul) return false;
        if(target==mul || index==nums.size()){
            if(target==mul){
                for(int i=0;i<nums.size();i++){
                    if(visited[i]==0){
                        if(mul<nums[i]) return false;
                        if(mul%nums[i]!=0) return false;
                        mul=mul/nums[i];
                    }
                }
                if(mul==1) return true;
            }
            return false;
        }
        visited[index]=1;
        bool take=solve(nums,target,index+1,visited,mul*nums[index]);
        visited[index]=0;
        bool nottake=solve(nums,target,index+1,visited,mul);
        return take || nottake;
    }
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        int n=nums.size();
        vector<int> visited(n,0);
        return solve(nums,target,0,visited,1);
        
    }
};
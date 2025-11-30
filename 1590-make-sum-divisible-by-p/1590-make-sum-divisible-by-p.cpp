class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total_sum = 0;
        for(auto num : nums){
            total_sum += num;
        }
        
        long long k = total_sum % p;
        if(k == 0) return 0;
        
        unordered_map<long long, int> mod_map;
        mod_map[0] = -1;
        long long prefix = 0;
        int min_length = nums.size() + 1;
        
        for(int i = 0; i < nums.size(); i++){
            prefix = (prefix + nums[i] % p) % p;
            long long required = (prefix - k + p) % p;
            if(mod_map.find(required) != mod_map.end()){
                min_length = min(min_length, i - mod_map[required]);
            }
            mod_map[prefix] = i;
        }
        
        return min_length <= nums.size() - 1 ? min_length : -1;
    }
};

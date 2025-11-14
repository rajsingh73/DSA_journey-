class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        int h=(intLength+1)/2;
        long long start=pow(10,h-1);
        long long end=pow(10,h)-1;
        vector<long long> ans;
        for(auto it: queries){
            int val=start+it-1;
            if(val>end) ans.push_back(-1);
            else{
                string s=to_string(val);
                string temp=s;
                if(intLength%2) temp.pop_back();
                reverse(temp.begin(),temp.end());
                string an=s+temp;
                ans.push_back(stoll(an));
            }
        }
        return ans;
    }
};
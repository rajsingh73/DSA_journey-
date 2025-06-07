class Solution {
public:
    string multiply(string nums1, string nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int> ans(n+m,0);
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int mul=(nums1[i]-'0')*(nums2[j]-'0');
                int pos1=i+j;
                int pos2=i+j+1;
                int value=mul+ans[pos2];
                ans[pos2]=value%10;
                ans[pos1]+=value/10;
            }
        }
        string s="";
        for(auto it:ans){
            if((s.empty() && it==0)) continue;
            s+=(it+'0');
        }
        return s;
        
    }
};
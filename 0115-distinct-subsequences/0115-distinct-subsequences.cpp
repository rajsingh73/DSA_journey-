class Solution {
public:
    int solve(string &s,string &t,int index1,int index2){
        if(index2<0) return 1;
        if(index1<0) return 0;
        int first=0;
        if(s[index1]==t[index2]){
            first=solve(s,t,index1-1,index2-1);
        }
        first+=solve(s,t,index1-1,index2);
        return first;
    }
    int numDistinct(string s, string t) {
        return solve(s,t,s.size()-1,t.size()-1);
    }
};
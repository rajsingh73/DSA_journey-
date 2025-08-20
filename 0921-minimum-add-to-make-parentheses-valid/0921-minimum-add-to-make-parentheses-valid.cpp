class Solution {
public:
    int minAddToMakeValid(string s) {
        int depth=0;
        int ans=0;
        for(auto it: s){
            if(it=='(') depth++;
            else{
                if(depth) depth--;
                else ans++;
            }
        }
        return ans+depth;
        
    }
};
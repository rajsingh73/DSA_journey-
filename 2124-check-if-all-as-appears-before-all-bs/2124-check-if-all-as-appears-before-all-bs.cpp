class Solution {
public:
    bool checkString(string s) {
        int bfind=0;
        for(auto c:s){
            if(c=='b') bfind=1;
            if(bfind && c=='a') return false;
        }
        return true;
        
    }
};
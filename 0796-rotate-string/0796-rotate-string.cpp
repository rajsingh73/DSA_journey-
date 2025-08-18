class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        string temp=s+s;
        int size=goal.size();
        int i=0;
        int limit=temp.size()-size;
        while(i<=limit){
            if(temp.substr(i,size)==goal) return true;
            i++;
        }
        return false;
        
    }
};
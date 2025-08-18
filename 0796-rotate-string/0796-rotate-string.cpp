class Solution {
public:
    bool isvalid(string s,string goal,int i){
        int j=0;
        int temp=i;
        while(i<s.size() && j<goal.size()){
            if(s[i]!=goal[j]) return false;
            i++;
            j++;
        }
        i=0;
        while(i<temp && j<goal.size()){
            if(s[i]!=goal[j]) return false;
            i++;
            j++;
        }
        return j==goal.size();

    }
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        for(int i=0;i<s.size();i++){
            if(s[i]==goal[0]){
                if(isvalid(s,goal,i)) return true;
            }
        }
        return false;
        
        
    }
};
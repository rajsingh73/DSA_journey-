class Solution {
public:
    string predictPartyVictory(string senate) {
        int first=0;
        int second=0;
        for(auto it :senate){
            if(it=='R'){
                if(first<0) first++;  
                else if(second>1) second--;
                else{
                    first++;
                    second--;
                }
            }
            else{
                if(second<0) second++;
                else if(first>1) first--;
                else{
                    second++;
                    first--;
                }
            }
        }
        if(first>second) return "Radiant";
        else return "Dire";
        
    }
}; 
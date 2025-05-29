class Solution {
public:
    int romanToInt(string s) {
        int val=0;
        int i=0;
        while(i<s.size()){
            if(s[i]=='I'){
                if(i+1<s.size() && s[i+1]=='V'){
                    val=val+4;
                    i++;
                }
                else if(i+1<s.size() && s[i+1]=='X'){
                    val=val+9;
                    i++;
                }
                else{
                    val=val+1;
                }
            }
            else if(s[i]=='X'){
                if(i+1<s.size() && s[i+1]=='L'){
                    val=val+40;
                    i++;
                }
                else if(i+1<s.size() && s[i+1]=='C'){
                    val=val+90;
                    i++;
                }
                else{
                    val=val+10;
                }
            }
            else if(s[i]=='C'){
                if(i+1<s.size() && s[i+1]=='D'){
                    val=val+400;
                    i++;
                }
                else if(i+1<s.size() && s[i+1]=='M'){
                    val=val+900;
                    i++;
                }
                else{
                    val=val+100;
                }
            }
            else if(s[i]=='V'){
                val=val+5;
            }
            else if(s[i]=='L'){
                val=val+50;
            }                    
            else if(s[i]=='D'){
                val=val+500;
            }
            else if(s[i]=='M'){
                val=val+1000;
            }
            i++;
        }
        return val;
        
    }
};
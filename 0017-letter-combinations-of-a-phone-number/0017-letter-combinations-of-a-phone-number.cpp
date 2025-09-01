class Solution {
public:
    void solve(vector<string> & ans,int index,string s,string digits){
        if(index==digits.size()){
            ans.push_back(s);
            return;
        }
        if(digits[index]=='2'){
            for(char c='a'; c<='c';c++){
                s.push_back(c);
                solve(ans,index+1,s,digits);
                s.pop_back();
            }
        }
        else if(digits[index]=='3'){
            for(char c='d'; c<='f';c++){
                s.push_back(c);
                solve(ans,index+1,s,digits);
                s.pop_back();
            }
        }
        else if(digits[index]=='4'){
            for(char c='g';c<='i';c++){
                s.push_back(c);
                solve(ans,index+1,s,digits);
                s.pop_back();
            }
        }
        else if(digits[index]=='5'){
            for(char c='j'; c<='l';c++){
                s.push_back(c);
                solve(ans,index+1,s,digits);
                s.pop_back();
            }
        }
        else if(digits[index]=='6'){
            for(char c='m'; c<='o';c++){
                s.push_back(c);
                solve(ans,index+1,s,digits);
                s.pop_back();
            }
        }
        else if(digits[index]=='7'){
            for(char c='p'; c<='s';c++){
                s.push_back(c);
                solve(ans,index+1,s,digits);
                s.pop_back();
            }
        }
        else if(digits[index]=='8'){
            for(char c='t'; c<='v';c++){
                s.push_back(c);
                solve(ans,index+1,s,digits);
                s.pop_back();
            }
        }
        else if(digits[index]=='9'){
            for(char c='w'; c<='z';c++){
                s.push_back(c);
                solve(ans,index+1,s,digits);
                s.pop_back();
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size()==0) return ans;
        string temp="";
        int index=0;
        solve(ans,index,temp,digits);
        return ans;
        
    }
};
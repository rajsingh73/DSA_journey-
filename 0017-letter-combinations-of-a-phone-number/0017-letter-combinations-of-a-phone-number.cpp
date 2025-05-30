class Solution {
public:
    void solve(string digits,int index,vector<string> & ans,string s){
        if(index==digits.size()){
            ans.push_back(s);
            return;
        }
        if(digits[index]=='2'){
            for(int i=97;i<=99;i++){
                char ch=(char)i;
                s.push_back(ch);
                solve(digits,index+1,ans,s);
                s.pop_back();
            }
        }
        if(digits[index]=='3'){
            for(int i=100;i<=102;i++){
                char ch=(char)i;
                s.push_back(ch);
                solve(digits,index+1,ans,s);
                s.pop_back();
            }
        }
        if(digits[index]=='4'){
            for(int i=103;i<=105;i++){
                char ch=(char)i;
                s.push_back(ch);
                solve(digits,index+1,ans,s);
                s.pop_back();
            }
        }
        if(digits[index]=='5'){
            for(int i=106;i<=108;i++){
                char ch=(char)i;
                s.push_back(ch);
                solve(digits,index+1,ans,s);
                s.pop_back();
            }
        }
        if(digits[index]=='6'){
            for(int i=109;i<=111;i++){
                char ch=(char)i;
                s.push_back(ch);
                solve(digits,index+1,ans,s);
                s.pop_back();
            }
        }
        if(digits[index]=='7'){
            for(int i=112;i<=115;i++){
                char ch=(char)i;
                s.push_back(ch);
                solve(digits,index+1,ans,s);
                s.pop_back();
            }
        }
        if(digits[index]=='8'){
            for(int i=116;i<=118;i++){
                char ch=(char)i;
                s.push_back(ch);
                solve(digits,index+1,ans,s);
                s.pop_back();
            }
        }
        if(digits[index]=='9'){
            for(int i=119;i<=122;i++){
                char ch=(char)i;
                s.push_back(ch);
                solve(digits,index+1,ans,s);
                s.pop_back();
            }
        }

    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        vector<string> ans;
        string s="";
        int index=0;
        solve(digits,index,ans,s);
        return ans;
        
    }
};
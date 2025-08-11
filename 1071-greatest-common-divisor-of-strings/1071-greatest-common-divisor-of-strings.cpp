class Solution {
public:
    bool find(string str1,string temp){
        int i=0;
        int n=temp.size();
        while(i<str1.size()){
            if(i+n>str1.size()) return false;
            if(str1.substr(i,n)!=temp) return false;
            i=i+n;
        }
        return true;
    }
    string gcdOfStrings(string str1, string str2) {
        if(str1.size()<str2.size()) return gcdOfStrings(str2,str1);
        string ans="";
        string temp="";
        for(int i=0;i<str2.size();i++){
            temp+=str2[i];
            if(find(str1,temp) && find(str2,temp)){
                ans=temp;
            }  
        }
        return ans;
    }
};
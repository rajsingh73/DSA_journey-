class Solution {
public:
    string shortestPalindrome(string s) {
        string tempo=s;
        reverse(s.begin(),s.end());
        string rev=s;
        s=tempo;
        string temp=s+'#'+rev;
        vector<int> lps(temp.size());
        lps[0]=0;
        int length=0;
        int j=1;
        while(j<temp.size()){
            if(temp[j]==temp[length]){
                length++;
                lps[j]=length;
                j++;
            }
            else{
                if(length==0){
                    lps[j]=0;
                    j++;
                }
                else length=lps[length-1];
            }
        }   
        int lastone=lps[temp.size()-1];
        string front=rev.substr(0,rev.size()-lastone);
        return front+s;

    }
};
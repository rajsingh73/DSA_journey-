class Solution {
public:
    string findme(int i,int j,vector<string> & words,int maxWidth,int space,int extraspace){
        string s="";
        for(int k=i;k<j;k++){
            s+=(words[k]);
            if(k==j-1) break;
            for(int m=0;m<space;m++) s+=" ";
            if(extraspace){
                s+=" ";
                extraspace--;
            }
        }
        while(s.size()<maxWidth) s+=" ";
        return s;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int i=0;
        int n=words.size();
        while(i<n){
            int j=i+1;
            int totallength=words[i].size();
            int gaddha=0;
            while(j<n && maxWidth>=words[j].size()+1+totallength+gaddha){
                totallength+=words[j].size();
                gaddha+=1;
                j++;
            }
            int vecant=maxWidth-totallength;
            int space=gaddha==0?0:vecant/gaddha;
            int extraspace=gaddha==0?0:vecant%gaddha;
            if(j==n){
                space=1;
                extraspace=0;
            }
            ans.push_back(findme(i,j,words,maxWidth,space,extraspace));
            i=j;
        }
        return ans;

        
    }
};
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string s="";
        int  i=0;
        int j=0;
        int n=word1.size();
        int m=word2.size();
        while(i<n&& j<m){
            if(i==j){
                s.push_back(word1[i]);
                i++;
            }
            else{
                s.push_back(word2[j]);
                j++;
            }
        }
        while(i<n){
            s.push_back(word1[i]);
            i++;
        }
        while(j<m){
            s.push_back(word2[j]);
            j++;
        }
        return s;
        
    }
};
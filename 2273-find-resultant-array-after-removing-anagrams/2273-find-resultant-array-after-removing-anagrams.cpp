class Solution {
public:
    bool isan(string first,string second){
        map<char,int> mp;
        for(char  it: first) mp[it]++;
        for(char  it: second){
            if(mp.find(it)==mp.end()) return false;
            mp[it]--;
            if(mp[it]==0) mp.erase(it);
        }
        return mp.empty();
    }
    vector<string> removeAnagrams(vector<string>& words) {
        for(int i=1;i<words.size();i++){
            if(isan(words[i],words[i-1])){
                string temp=words[i-1];
                words[i-1]="";
                words[i]=temp;
            }
        }
        vector<string> ans;
        for(string it: words){
            if(it!="") ans.push_back(it);
        }
        return ans;
    }
};
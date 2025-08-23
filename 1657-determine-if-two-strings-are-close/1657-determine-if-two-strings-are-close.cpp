class Solution {
public:
    bool closeStrings(string word1, string word2) {
        map<char,int> mp;
        map<char,int> temp;
        for(auto it: word1) mp[it]++;
        for(auto it: word2) {
            if(mp.find(it)==mp.end()) return false;
            temp[it]++;
        }
        priority_queue<int> first;
        priority_queue<int> second;
        for(auto it: mp) first.push(it.second);
        for(auto it : temp ) second.push(it.second);
        while(first.size() && second.size()){
            if(first.top()==second.top()){
                first.pop();
                second.pop();
            }
            else return false;
        }
        return first.size()==second.size();
        
    }
};
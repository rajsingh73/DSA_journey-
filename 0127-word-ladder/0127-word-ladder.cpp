class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st;
        for(auto s:wordList) st.insert(s);
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                pair<string,int> p=q.front();
                q.pop();
                string value=p.first;
                int way=p.second;
                for(int i=0;i<value.size();i++){
                    for(char c='a'; c<='z';c++){
                        string temp=value;
                        temp[i]=c;
                        if(temp==endWord && st.find(temp)!=st.end()) return way+1;
                        else if(st.find(temp)!=st.end()){
                            st.erase(temp);
                            q.push({temp,way+1});
                        }
                    }
                }
            }
        }
        return 0;  
    }
};
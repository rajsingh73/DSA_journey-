class Twitter {
public:
    vector<vector<int>> twitter;
    vector<pair<int,int>> tweet;
    Twitter() {
        twitter.resize(500);
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweet.insert(tweet.begin(),{userId,tweetId});
    }
    bool val(int id,int fid){
        for(auto it: twitter[id]) if(it==fid) return true;
        return false;
    }
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        for(auto it: tweet){
            if(it.first==userId) ans.push_back(it.second);
            else if(val(userId,it.first)) ans.push_back(it.second);
            if(ans.size()==10) return ans;
        }
        return ans;  
    }
    
    void follow(int followerId, int followeeId) {
        twitter[followerId].push_back(followeeId);
        
    }
    
    void unfollow(int followerId, int followeeId) {
        for(int i=0;i<twitter[followerId].size();i++){
            if(twitter[followerId][i]==followeeId) {
                twitter[followerId].erase(twitter[followerId].begin()+i);
                break;
            }
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
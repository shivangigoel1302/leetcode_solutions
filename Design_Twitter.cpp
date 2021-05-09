class Twitter {
public:
    /** Initialize your data structure here. */
    map<int,set<int>>follower;
    map<int,vector<pair<int,int>>>tweets;
    int time;
    Twitter() {
        time = 0;
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time,tweetId});
        time++;
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int>ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto it : tweets[userId]){
            if(pq.size() < 10){
                pq.push(it);
            }
            else{
                if(it.first > pq.top().first){
                    pq.pop();
                    pq.push(it);
                }
            }
        }
        for(auto fol : follower[userId]){
            for(auto it :tweets[fol]){
                if(pq.size() < 10){
                    pq.push(it);
                }
                else{
                    if(it.first > pq.top().first){
                        pq.pop();
                        pq.push(it);
                    }
                }
            }
        }
        while(pq.size() > 0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId){
            follower[followerId].insert(followeeId);
        }
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        follower[followerId].erase(followeeId);
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

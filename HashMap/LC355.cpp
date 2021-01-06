// 355. Design Twitter
// Design a simplified version of Twitter where users can post tweets, follow/unfollow another user and is able to see the 10 most recent tweets in the user's news feed. Your design should support the following methods:

// postTweet(userId, tweetId): Compose a new tweet.
// getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
// follow(followerId, followeeId): Follower follows a followee.
// unfollow(followerId, followeeId): Follower unfollows a followee.
struct mycomp{
     bool operator()(pair<int,int> &left,pair<int,int> & right){
          return left.second < right.second;
     }  
};

class Twitter {
public:
    /** Initialize your data structure here. */
    unordered_map<int,unordered_set<int>> flw;//keeps track of followers of each user
    unordered_map< int,vector<pair<int,int>> > db;//keeps track of users tweets
    int time=0;
    
    Twitter() {
        time=0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        db[userId].push_back({tweetId,time});
        time++;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        
        //push all tweets of user+his followers in the queue
        priority_queue<pair<int,int>,vector<pair<int,int>>,mycomp> pq;
        
        for(auto ele:db[userId])//self tweets
        {
            pq.push(ele);
        }
        
        for(auto follower:flw[userId])
        {
            for(auto ele:db[follower])//followers tweets
                pq.push(ele);
        }
        
        
        vector<int> ans;
        while(ans.size()!=10 && !pq.empty())
        {
            ans.push_back(pq.top().first);
            pq.pop();  
        }
    
        return ans;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId)
            flw[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(followerId!=followeeId)
            flw[followerId].erase(followeeId);
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
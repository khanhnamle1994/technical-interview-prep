/* Design a simplified version of Twitter where users can post tweets, follow/unfollow another user and is able to see the 10 most recent tweets in
the user's news feed. Your design should support the following methods:

1. postTweet(userId, tweetId): Compose a new tweet.
2. getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
3. follow(followerId, followeeId): Follower follows a followee.
4. unfollow(followerId, followeeId): Follower unfollows a followee. */

/* Example:

Twitter twitter = new Twitter();

// User 1 posts a new tweet (id = 5).
twitter.postTweet(1, 5);

// User 1's news feed should return a list with 1 tweet id -> [5].
twitter.getNewsFeed(1);

// User 1 follows user 2.
twitter.follow(1, 2);

// User 2 posts a new tweet (id = 6).
twitter.postTweet(2, 6);

// User 1's news feed should return a list with 2 tweet ids -> [6, 5].
// Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
twitter.getNewsFeed(1);

// User 1 unfollows user 2.
twitter.unfollow(1, 2);

// User 1's news feed should return a list with 1 tweet id -> [5],
// since user 1 is no longer following user 2.
twitter.getNewsFeed(1); */

class Tweet {
    friend class Twitter;
    friend class Compare;
  private:
    int id;
    int time;
  public:
    Tweet(int id, int time) : id(id), time(time) {
    }
};

class Compare {
    public:
        bool operator()(pair<vector<Tweet>::iterator,vector<Tweet>::iterator> p1, pair<vector<Tweet>::iterator,vector<Tweet>::iterator> p2 ) {
            return (p1.first->time < p2.first->time);
        }
};

class Twitter {
private:
    int time;
    unordered_map<int, unordered_set<int>> followmap;
    unordered_map<int, vector<Tweet>> tweets;

public:
    /** Initialize your data structure here. */
    Twitter( int time=0) : time(time) {

    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
      tweets[userId].insert(tweets[userId].begin(),Tweet(tweetId,time++));
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {

        priority_queue<pair<vector<Tweet>::iterator,vector<Tweet>::iterator>, vector<pair<vector<Tweet>::iterator,vector<Tweet>::iterator>>, Compare> pq;
        vector<int> res;
        for (auto follower : followmap[userId]) {
            if (tweets.count(follower) && tweets[follower].size())
                pq.push(make_pair(tweets[follower].begin(), tweets[follower].end()));
        }
        if (tweets.count(userId) && tweets[userId].size())
            pq.push(make_pair(tweets[userId].begin(),tweets[userId].end()));
        for (int i=0; i<10 && !pq.empty(); ++i) {
            auto temp = pq.top();
            pq.pop();
            res.push_back(temp.first->id);
            if (++temp.first != temp.second) pq.push(temp);
        }
        return res;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
      if (followerId != followeeId) followmap[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
      if (followmap.count(followerId)) followmap[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */

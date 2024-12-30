class Twitter {

    private static class Tweet {
        int id;
        int timestamp;

        Tweet(int id, int timestamp) {
            this.id = id;
            this.timestamp = timestamp;
        }
    }

    private Map<Integer, List<Tweet>> posts;
    private Map<Integer, Set<Integer>> followers;
    private int time;

    public Twitter() {
        posts = new HashMap<>();
        followers = new HashMap<>();
        time = 0;
    }

    public void postTweet(int userId, int tweetId) {
        posts.computeIfAbsent(userId, k -> new ArrayList<>()).add(new Tweet(tweetId, time++));
    }

    public List<Integer> getNewsFeed(int userId) {
        PriorityQueue<Tweet> pq = new PriorityQueue<>((a, b) -> b.timestamp - a.timestamp);

        if (posts.containsKey(userId)) {
            pq.addAll(posts.get(userId));
        }

        Set<Integer> userFollowers = followers.getOrDefault(userId, new HashSet<>());
        for (Integer follower : userFollowers) {
            if (posts.containsKey(follower)) {
                pq.addAll(posts.get(follower));
            }
        }

        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < 10 && !pq.isEmpty(); i++) {
            result.add(pq.poll().id);
        }

        return result;
    }

    // public List<Integer> getNewsFeed(int userId) {
    //     List<Tweet> feed = new ArrayList<>();
    //     if (posts.containsKey(userId)) {
    //         feed.addAll(posts.get(userId));
    //     }

    //     Set<Integer> userFollowers = followers.getOrDefault(userId, new HashSet<>());
    //     for (Integer follower : userFollowers) {
    //         if (posts.containsKey(follower)) {
    //             feed.addAll(posts.get(follower));
    //         }
    //     }

    //     feed.sort((a, b) -> b.timestamp - a.timestamp);

    //     List<Integer> result = new ArrayList<>();
    //     for (int i = 0; i < Math.min(10, feed.size()); i++) {
    //         result.add(feed.get(i).id);
    //     }

    //     return result;
    // }


    public void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            followers.computeIfAbsent(followerId, k -> new HashSet<>()).add(followeeId);
        }
    }

    public void unfollow(int followerId, int followeeId) {
        followers.getOrDefault(followerId, new HashSet<>()).remove(followeeId);
    }
}

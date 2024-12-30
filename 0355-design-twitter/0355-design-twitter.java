class Twitter {

    Map<Integer, ArrayList<Integer>> posts = new HashMap<>();
    Map<Integer, Integer> postTime = new HashMap<>();

    Map<Integer, Set<Integer>> followers = new HashMap<>();
    int time = 1;

    public Twitter() {

    }

    public void postTweet(int userId, int tweetId) {
        ArrayList<Integer> userPosts = posts.getOrDefault(userId, new ArrayList<>());
        userPosts.add(tweetId);

        postTime.put(tweetId, time++);
        posts.put(userId, userPosts);
    }

    public List<Integer> getNewsFeed(int userId) {
        
        Set<Integer> userFollowers = followers.getOrDefault(userId, new HashSet<>());
        Set<Integer> allTweets = new HashSet<>(posts.getOrDefault(userId, new ArrayList<>()));
        
        for (Integer follower : userFollowers) {
            allTweets.addAll(posts.getOrDefault(follower, new ArrayList<>()));
        }
        
        List<Integer> sortedTweets = new ArrayList<>(allTweets);
        sortedTweets.sort((a, b) -> Integer.compare(postTime.get(b), postTime.get(a)));
        
        return sortedTweets.subList(0, Math.min(10, sortedTweets.size()));
    }


    public void follow(int followerId, int followeeId) {
        Set<Integer> userFollowers = followers.getOrDefault(followerId, new HashSet<>());
        userFollowers.add(followeeId);

        followers.put(followerId, userFollowers);
    }

    public void unfollow(int followerId, int followeeId) {
        Set<Integer> userFollowers = followers.getOrDefault(followerId, new HashSet<>());
        userFollowers.remove(followeeId);
        
        followers.put(followerId, userFollowers);
    }
}
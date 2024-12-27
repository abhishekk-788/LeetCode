class TrieNode {
    TrieNode[] child;
    int sum;

    public TrieNode() {
        child = new TrieNode[26];
        sum = 0;
    }
}

class MapSum {
    private TrieNode root;
    private Map<String, Integer> map;

    public MapSum() {
        root = new TrieNode();
        map = new HashMap<>();
    }

    public void insert(String key, int val) {
        int delta = val - map.getOrDefault(key, 0);
        map.put(key, val);
        TrieNode curr = root;
        
        for (char c : key.toCharArray()) {
            int index = c - 'a';
            if (curr.child[index] == null) {
                curr.child[index] = new TrieNode();
            }
            curr = curr.child[index];
            curr.sum += delta;
        }
    }

    public int sum(String prefix) {
        TrieNode curr = root;
        for (char c : prefix.toCharArray()) {
            int index = c - 'a';
            if (curr.child[index] == null) {
                return 0;
            }
            curr = curr.child[index];
        }
        return curr.sum;
    }
}

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key, val);
 * int param_2 = obj.sum(prefix);
 */

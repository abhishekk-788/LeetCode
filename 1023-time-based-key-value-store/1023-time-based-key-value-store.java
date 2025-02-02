class TimeMap {
    Map<String, TreeMap<Integer, String>> store;
    public TimeMap() {
        store = new HashMap<>();
    }

    public void set(String key, String value, int timestamp)
    {
        TreeMap<Integer, String> map = store.getOrDefault(key, new TreeMap<>());
        map.put(timestamp, value);
        store.put(key, map);
    }

    public String get(String key, int timestamp) {
        TreeMap<Integer, String> map = store.getOrDefault(key, new TreeMap<>());
        if(map.size() == 0) return "";

        Integer resultKey = map.floorKey(timestamp);
        return (resultKey == null) ? "": map.get(resultKey);
    }
}

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap obj = new TimeMap();
 * obj.set(key,value,timestamp);
 * String param_2 = obj.get(key,timestamp);
 */
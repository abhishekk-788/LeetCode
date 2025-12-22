class Solution {
    public int longestSubsequence(int[] arr, int d) {
        HashMap<Integer, Integer> hash = new HashMap<>();
        int mx = 0;
        for(int x : arr) 
        {
            hash.put(x, hash.getOrDefault(x-d, 0) + 1);
            mx = Math.max(mx, hash.get(x));
        }
        return mx;
    }
}
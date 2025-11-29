class TopVotedCandidate {
    TreeMap<Integer, Integer> hash;
    public TopVotedCandidate(int[] persons, int[] times) {
        hash = new TreeMap<>();
        int n = persons.length;

        int[] count = new int[persons.length];
        int max = 0;
        for(int i = 0; i < n; i++) {
            count[persons[i]]++;
            if(count[persons[i]] >= max) {
                max = count[persons[i]];
                hash.put(times[i], persons[i]);
            }
        }
    }
    public int q(int t) {
        return hash.floorEntry(t).getValue();
    }
}
/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */
class TopVotedCandidate {
    int[] times;
    int[] leaders; 

    public TopVotedCandidate(int[] persons, int[] times) {
        this.times = times;
        int n = persons.length;

        int maxPerson = 0;
        for (int p : persons) maxPerson = Math.max(maxPerson, p);
        int[] count = new int[maxPerson + 1];

        leaders = new int[n];
        int leader = -1;
        int leaderCount = 0;

        for (int i = 0; i < n; i++) {
            int p = persons[i];
            count[p]++;

            if (count[p] >= leaderCount) {
                leader = p;
                leaderCount = count[p];
            }
            leaders[i] = leader;
        }
    }

    public int q(int t) {
        int l = 0, r = times.length - 1;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (times[mid] <= t) l = mid;
            else r = mid - 1;
        }
        return leaders[l];
    }
}
/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */
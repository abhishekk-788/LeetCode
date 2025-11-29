class Solution {
    public int binarySearch(ArrayList <int[]> list, int target) {
        int left = 0, right = list.size() - 1, ans = -1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(list.get(mid)[0] == target) {
                return list.get(mid)[1];
            } else if(list.get(mid)[0] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
                ans = list.get(mid)[1];
            }
        }
        return ans;
    }
    public int[] findRightInterval(int[][] intervals) 
    {
        ArrayList <int[]> list = new ArrayList<>();
        int n = intervals.length;
        for(int i = 0; i < n; i++) {
            list.add(new int[] {intervals[i][0], i});
        }
        Collections.sort(list, (a, b)->a[0]-b[0]);
        int[] ans = new int[n];
        for(int i = 0; i < n; i++) {
            int x = intervals[i][0], y = intervals[i][1];
            int idx = binarySearch(list, y);
            if(idx == -1) {
                ans[i] = -1;
            } else {
                ans[i] = idx;
            }
        }
        return ans;
    }
}
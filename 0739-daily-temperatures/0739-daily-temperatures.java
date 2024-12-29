class Solution {
    public int[] dailyTemperatures(int[] temperatures) 
    {
        Stack<int[]> st = new Stack<>();
        int n = temperatures.length;

        int[] nxtGreater = new int[n];
        Arrays.fill(nxtGreater, 0);

        for (int i = 0; i < n; i++) {
            while (!st.isEmpty() && temperatures[i] > st.peek()[0]) {
                int[] top = st.pop();
                nxtGreater[top[1]] = i - top[1];
            }
            st.push(new int[] {temperatures[i], i});
        }

        return nxtGreater;
    }
}

/*

1 1 4 2 

73, 0
74, 1


69, 4
71, 3
75, 2

*/
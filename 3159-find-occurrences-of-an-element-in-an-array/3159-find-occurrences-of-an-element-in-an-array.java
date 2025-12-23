class Solution {
    public int[] occurrencesOfElement(int[] nums, int[] queries, int x) {
        List<Integer> list = new ArrayList<>();
        for(int i = 0; i < nums.length; i++)
        {
            if(nums[i] == x) {
                list.add(i);
            }
        }

        int n = list.size();
        int[] ans = new int[queries.length];

        for(int i = 0; i < queries.length; i++)
        {
            if(queries[i] > n) {
                ans[i] = -1;
            }
            else ans[i] = list.get(queries[i]-1);
        }
        return ans;
    }
}
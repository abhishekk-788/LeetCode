class Solution {
    List<List<Integer>> result;
    public void solve(int i, int k, int n, List<Integer> list) {
        if(k == 0 && n == 0) 
        {
            result.add(new ArrayList<>(list));
            return;
        }
        if(i > 9 || k == 0 || n < 0) {
            return;
        }

        list.add(i);
        solve(i+1, k - 1, n - i, list);
        list.remove(list.size() - 1);
        solve(i + 1, k, n, list);
    }
    public List<List<Integer>> combinationSum3(int k, int n) 
    {
        result = new ArrayList<>();
        List<Integer> list = new ArrayList<>();

        solve(1, k, n, list);
        return result;
    }
}
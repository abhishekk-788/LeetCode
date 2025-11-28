class Solution {
    List<List<Integer>> list;
    public void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    void solve(int i, int n, int[] nums) {
        if(i == n) {
            List<Integer> arr = new ArrayList<>();
            for (int num : nums) {
                arr.add(num);
            }
            list.add(arr);
            return;
        }

        for(int k = i; k < n; k++)
        {
            swap(nums, i, k);
            solve(i+1, n, nums);
            swap(nums, i, k);
        }
    }
    public List<List<Integer>> permute(int[] nums) {
        list = new ArrayList<>();

        int n = nums.length;
        solve(0, n, nums);

        return list;
    }
}
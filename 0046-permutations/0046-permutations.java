class Solution {
    List<List<Integer>> result = new ArrayList<>();

    public void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    public void F(int[] nums, int i, int n) {
        if (i == n - 1) 
        {
            List<Integer> list = new ArrayList<>();
            for (int num : nums) {
                list.add(num);
            }
            result.add(list);
            return;
        }

        for (int k = i; k < n; k++) {
            swap(nums, i, k);
            F(nums, i + 1, n);
            swap(nums, i, k);
        }
    }

    public List<List<Integer>> permute(int[] nums) {
        F(nums, 0, nums.length);
        return result;
    }
}

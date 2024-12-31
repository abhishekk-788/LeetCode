class Solution {
    public int[] calculateSubsetSums(int[] array, int size) {
        long totalSubsets = (1L << size);
        int[] subsetSums = new int[(int) totalSubsets];

        for (int subsetMask = 0; subsetMask < totalSubsets; subsetMask++) {
            int sum = 0;
            for (int bitIndex = 0; bitIndex < size; bitIndex++) {
                if ((subsetMask & (1 << bitIndex)) != 0) {
                    sum += array[bitIndex];
                }
            }
            subsetSums[subsetMask] = sum;
        }
        return subsetSums;
    }

    public int findClosestDifference(int[] sortedArray, int target) {
        int left = 0, right = sortedArray.length - 1;
        int minDifference = Integer.MAX_VALUE;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            minDifference = Math.min(minDifference, Math.abs(sortedArray[mid] - target));

            if (sortedArray[mid] == target) {
                return 0;
            } else if (sortedArray[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return minDifference;
    }

    public int minAbsDifference(int[] nums, int goal) {
        int totalSize = nums.length;
        int leftSize = (totalSize + 1) / 2;

        int[] leftHalf = new int[leftSize];
        int[] rightHalf = new int[totalSize - leftSize];

        for (int i = 0; i < leftSize; i++) {
            leftHalf[i] = nums[i];
        }
        for (int i = leftSize; i < totalSize; i++) {
            rightHalf[i - leftSize] = nums[i];
        }

        int[] leftSubsetSums = calculateSubsetSums(leftHalf, leftSize);
        int[] rightSubsetSums = calculateSubsetSums(rightHalf, totalSize - leftSize);

        Arrays.sort(rightSubsetSums);

        int minDifference = Integer.MAX_VALUE;
        for (int leftSum : leftSubsetSums) {
            int closestDiff = findClosestDifference(rightSubsetSums, goal - leftSum);
            minDifference = Math.min(minDifference, closestDiff);
        }

        return minDifference;
    }
}

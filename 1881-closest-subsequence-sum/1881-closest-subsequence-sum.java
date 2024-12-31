class Solution {
    public int[] subsetSums(int arr[], int n)
    {
        long totalSubsets = (1L << n);
        int[] allPossibleSubsetSums = new int[(int) totalSubsets];

        int k = 0;
        for(int i = 0; i < totalSubsets; i++)
        {
            int sum = 0;
            for(int j = 0; j < n; j++)
            {
                if((i & (1 << j)) != 0) {
                    sum += arr[j];
                }
            }
            allPossibleSubsetSums[k++] = sum;
        }
        return allPossibleSubsetSums;
    }

    public int binarySearchClosest(int[] arr, int num) {
        int l = 0, r = arr.length - 1;
        int closest = Integer.MAX_VALUE;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            closest = Math.min(closest, Math.abs(arr[mid] - num));
            
            if(arr[mid] == num) 
                return 0;
            else if (arr[mid] < num) 
                l = mid + 1;
            else r = mid - 1;
        }

        return closest;
    }
    
    public int minAbsDifference(int[] nums, int goal) 
    {
        int n = nums.length;
        int mid = ((n+1)/2);

        int[] left = new int[mid];
        int[] right = new int[n-mid];

        for(int i = 0; i < mid; i++) {
            left[i] = nums[i];
        }   
        int k = 0;
        for(int j = mid; j < n; j++) {
            right[k++] = nums[j];
        }

        int[] leftSubsetSum = subsetSums(left, mid);
        int[] rightSubsetSum = subsetSums(right, n-mid);

        Arrays.sort(rightSubsetSum);

        int i = 0, x = leftSubsetSum.length, y = rightSubsetSum.length;
        int mn = Integer.MAX_VALUE;
        while(i < x) 
        {
            int ls = leftSubsetSum[i];
            int closest = binarySearchClosest(rightSubsetSum, goal - ls);

            mn = Math.min(mn, closest);
            i++;
        }

        return mn;
    }
}
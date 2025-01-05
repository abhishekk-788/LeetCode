class Solution {
    public int binarySearch(List<Integer> indices, int j) 
    {
        int low = 0, high = indices.size() - 1;
        while (low <= high) 
        {
            int mid = low + (high - low) / 2;
            if (indices.get(mid) <= j) {
                low = mid + 1;
            } 
            else high = mid - 1;
        }
        return low;
    }

    public int threeSumMulti(int[] arr, int target) 
    {
        int n = arr.length;
        Map<Integer, List<Integer>> hash = new HashMap<>();

        for (int i = 0; i < n; i++) {
            List<Integer> pos = hash.getOrDefault(arr[i], new ArrayList<>());
            pos.add(i);
            hash.put(arr[i], pos);
        }

        long cnt = 0;
        for (int i = 0; i < n; i++) 
        {
            for (int j = i + 1; j < n; j++) 
            {
                int val = target - (arr[i] + arr[j]);
                if (hash.containsKey(val)) {
                    List<Integer> indices = hash.get(val);
                    int index = binarySearch(indices, j);
                    cnt += (indices.size() - index);
                }
            }
        }

        return (int) (cnt % (1000000007));
    }
}

/*

arr[i] + arr[j] + arr[k] = target
arr[k] = target - (arr[i] + arr[j])

{
    2: 1, 4, 7
}

*/
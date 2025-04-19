class Solution {
public:
    int longestMountain(vector<int>& arr) 
    {
        int maxLength = 0, i = 0, n = arr.size();
        bool uphill = false, downhill = false;
        
        while (i < n- 1) 
        {
            if (arr[i] < arr[i + 1]) 
            {
                int start = i;
                
                while (i < n - 1 && arr[i] < arr[i + 1]) {
                    i++;
                    uphill = true;
                }
                
                while (i < n - 1 && arr[i] > arr[i + 1]) {
                    i++;
                    downhill = true;
                }
                
                if (uphill && downhill) {
                    maxLength = max(maxLength, i - start + 1);
                }
                
                uphill = downhill = false;
            } 
            else i++;
        }
        
        return maxLength;
    }
};

/*

3 2 4 5 7 8 5 3 2 1 3 4 5 6 7 8 9 8 7 6 5 4 3 2

*/
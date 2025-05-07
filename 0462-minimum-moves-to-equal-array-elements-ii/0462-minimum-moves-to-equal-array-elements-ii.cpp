class Solution {
public:
    int minMoves2(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int ans = 0;

        int mid = nums[n/2];
        cout << mid << "\n";
        
        for(int i = 0; i < n; i++) {
            ans += abs(nums[i] - mid);
        }

        return ans;
    }
};

/*

1, 2, 6, 8, 9, 10
1 4 2 1 1

1 + 8 + 9
9 + 8 + 1



*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int n = numbers.size(), i = 0, j = n-1;
        while(i < j)
        {
            int s = numbers[i] + numbers[j];
            if(s == target) {
                return {i+1, j+1};
            }
            else if(s < target) i++;
            else j--;
        }
        
        return {};
    }
};

/*

7 9 10 16 18 24 29

27

*/
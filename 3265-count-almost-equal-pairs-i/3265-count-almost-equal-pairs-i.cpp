class Solution {
public:
    bool isValid(int x, int y)
    {
        if(x == y) return true;
        
        string s1 = to_string(x);
        string s2 = to_string(y);
    
        for (int i = 0; i < s1.length(); ++i) 
        {
            for (int j = i + 1; j < s1.length(); ++j) 
            {
                swap(s1[i], s1[j]);
                if (to_string(stoi(s1)) == s2) return true;
                
                swap(s1[i], s1[j]);
            }
        }
        return false;
    }
    
    int countPairs(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end(), greater<int>());
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                if(isValid(nums[i], nums[j])) cnt++;   
            }
        }
        
        return cnt;
    }
};

/*

3 30 30 30


123456
123546

*/
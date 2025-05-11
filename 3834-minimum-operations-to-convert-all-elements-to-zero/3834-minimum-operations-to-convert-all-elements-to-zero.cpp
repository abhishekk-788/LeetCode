class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
        int n = nums.size();
        map<int,vector<int>> hash;
        stack<int> st;
        st.push(0);
        int count = 0;
        for(int i = 0 ; i < n; i++)
        {
            if(st.top()<nums[i])
            {
                count ++;
                st.push(nums[i]);
            }
            else if(st.top()>nums[i])
            {
                st.pop();
                i--;
            }
        }
        return count;
    }
};
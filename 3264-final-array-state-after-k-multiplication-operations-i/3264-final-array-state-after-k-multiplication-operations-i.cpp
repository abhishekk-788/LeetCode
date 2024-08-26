class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > pq;
        
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }
        
        while(k != 0)
        {
            auto ele = pq.top();
            pq.pop();
            
            pq.push({ele.first * multiplier, ele.second});
            k--;
        }
        
        while(!pq.empty())
        {
            auto ele = pq.top();
            pq.pop();
            
            nums[ele.second] = ele.first;
        }
        
        return nums;
    }
};
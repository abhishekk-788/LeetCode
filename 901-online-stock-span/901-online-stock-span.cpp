class StockSpanner {
public:
    stack<pair<int, int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int cnt = 1;
        while(!st.empty() && price >= st.top().first) {
            int p = st.top().first, sz = st.top().second;
            cnt += sz;
            
            st.pop();
        }
        
        st.push({price, cnt});
        return cnt;
    }
};

/*


60, 1
70, 2
80, 1
100, 1

*/

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
class Solution {
public:
using ll = long long;
ll minn = -10000000000005;
    ll helper(vector<int>& a, vector<int>& b, int i , int j, vector<vector<ll>>&dp,int cnt){
        if(cnt == 4){
            return 0;
        }
        if(i >= 4 || j >= b.size()) return minn;
        if(dp[i][j] != minn) return dp[i][j];
        ll take = (1LL*a[i]*b[j]) + helper(a,b,i+1,j+1,dp,cnt+1);
        ll nottake = helper(a,b,i,j+1,dp,cnt);
        return dp[i][j] = max(take,nottake);
    }
    long long maxScore(vector<int>& a, vector<int>& b) {
        vector<vector<ll>>dp(5,vector<ll>(b.size()+1,minn));
        return helper(a,b,0,0,dp,0);
    }
};
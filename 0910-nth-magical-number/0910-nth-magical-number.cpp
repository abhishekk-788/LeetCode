class Solution {
public:
    const int mod = 1e9 + 7;
    long long gcd(long long int a, long long int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    long long lcm(int a, int b) {
        return (a / gcd(a, b)) * b;
    }
    
    int nthMagicalNumber(int n, int a, int b) {
        long long lc = lcm(a,b);
        long long low = 1, high = 1LL * n * min(a,b);
        while(low < high)
        {
            long long mid = low + (high - low) / 2;
            long long cnt = (mid/a) + (mid/b) - (mid/lc);

            if(cnt < n) low = mid + 1;
            else high = mid;
        }
        return low % mod;   
    }
};


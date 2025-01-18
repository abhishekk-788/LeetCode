class Solution {
    public int maximumGroups(int[] grades) 
    {
        int n = grades.length;
        int ans = 0, i = 1, k = 1;
        while(i <= n) {
            ans += 1;
            i = i + (++k);

            System.out.println(i);
        }
        return ans;
    }
}

/*

1 + 2 

[10,6,12,7,3,5]
[3, 5, 6, 7, 10, 12]

1 + 2 + 3 + 4 < n
(x) * (x + 1)/2 < n
(x) * (x + 1) < 2n
x^2 + x < 2n
x^2 + x - 2n < 0

-1 + (1 + 8n)/2 = 4n
-1 - (1 + 8n)/2 = - (4n+2)

3 8 14 21 31 43

n^2 + n - l = 0
n^2 + 2n - n -l = 0

n(n+2) - (n+l) = 0
(n-1) 

[3]

*/
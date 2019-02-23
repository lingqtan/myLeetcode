class Solution {
    int abs(int x) { return (x>0) ? x : -x; }
public:
    int reverse(int x) {
        if (x == 0 || x == INT_MIN || x == INT_MAX) return 0;
        int sign = (x>0) ? 1 : -1;
        x = abs(x);
        int bit[32];
        int i = 0;
        while (x) {
            bit[i++] = x % 10;
            x /= 10;
        }
        long long ans = 0;
        int s = i-1;
        while (s >= 0 && bit[s] == 0) s--;
        if (s < 0) return 0;
        for (int j = 0; j <= s; j++) {
            if (ans * 5 + bit[j] > INT_MAX - ans * 5) return 0;
            ans = ans * 10 + bit[j];
        }
        return ans * sign;
    }
};
class Solution {
    const int LIM = (int)sqrt(INT_MAX);
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        if (x <= 3) return 1;
        int s = 2, t = x - 1;
        while (t - s > 1) {
            int mid;
            if (s > INT_MAX - t) mid = INT_MAX / 2;
            else mid = (s + t) / 2;
            if (mid > LIM) t = mid;
            else {
                if (mid * mid == x) return mid;
                if (mid * mid > x) t = mid;
                else s = mid;
            }
        }
        return s;
    }
};
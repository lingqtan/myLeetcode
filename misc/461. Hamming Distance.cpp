class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            ans += (((x >> i) % 2) + ((y >> i) % 2)) % 2;
        }
        return ans;
    }
};
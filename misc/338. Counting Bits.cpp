class Solution {
public:
    int table[256];
    void make_table() {
        for (int i = 0; i < 256; i++) {
            int c = 0, v = i;
            while (v) {v &= v-1; c++;}
            table[i] = c;
        }
    }
    vector<int> countBits(int num) {
        make_table();
        vector<int> ans;
        for (int i = 0; i <= num; i++) {
            int v = i, c = 0;
            while (v) {
                c += table[v % 256];
                v /= 256;
            }
            ans.push_back(c);
        }
        return ans;
    }
};
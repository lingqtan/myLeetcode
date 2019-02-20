class Solution {
public:
    string longestPalindrome(string s) {
        int maxlen = -1, sp = 0, tp = 0;
        for(int i = 0; i < s.length(); i++) {
            int t_ans = 1;
            int j = i, k = 1, tsp = 0, ttp = 0;
            while (j-k >= 0 && j+k < s.length()) {
                if (s[j-k] == s[j+k]) {
                    tsp = j-k, ttp = j+k;
                    t_ans+=2; k++;
                }
                else break;
            }
            if (t_ans > maxlen) { sp = tsp, tp = ttp, maxlen = t_ans; }
            t_ans = 0, j = i, k = 0, tsp = 0, ttp = 0;
            while (j-k >= 0 && j+k+1 < s.length()) {
                if (s[j-k] == s[j+k+1]) {
                    tsp = j-k, ttp = j+k+1;
                    t_ans+=2; k++;
                }
                else break;
            }
            if (t_ans > maxlen) { sp = tsp, tp = ttp, maxlen = t_ans; }
        }
        return s.substr(sp, tp-sp+1);
    }
};
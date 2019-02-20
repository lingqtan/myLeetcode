class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256, -1);
        int i = 0, j = 0, t_ans = 0, ans = 0;
        while (i < s.length() && j < s.length()) {
            for (int k = 0; k < hash.size(); k++) hash[k] = -1;
            t_ans = 0;
            j = i;
            while (hash[s[j]] == -1 && j < s.length()) {
                hash[s[j]] = j;
                j++;
                t_ans++;
            }
            if (t_ans > ans) ans = t_ans;
            if (j < s.length()) i = hash[s[j]] + 1;
        }
        return ans;
    }
};
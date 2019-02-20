class Solution {
public:
    int numJewelsInStones(string J, string S) {
        std::sort(J.begin(), J.end());
        std::sort(S.begin(), S.end());
        int i = 0, j = 0, ans = 0;
        while(i < J.length()) {
            while(j < S.length() && S[j] < J[i]) j++;
            while(j < S.length() && S[j] == J[i]) {
                j++;
                ans++;
            }
            i++;
        }
        return ans;
    }
};
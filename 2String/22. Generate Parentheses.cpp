class Solution {
    void solve(int n, int lp, int rp, string str, vector<string>& ans) {
        if (str.length() == n * 2) {
            ans.push_back(str);
            return;
        }
        if (lp + 1 <= n && lp + 1 >= rp) {
            solve(n, lp+1, rp, str + "(", ans);
        }        
        if (rp + 1 <= n && lp >= rp + 1) {
            solve(n, lp, rp+1, str + ")", ans);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(n, 0, 0, "", ans);
        return ans;
    }
};
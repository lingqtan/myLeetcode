class Solution {
    void solve(int status, vector<int>& cur, vector<int>& nums, vector<vector<int> >& ans) {
        if (cur.size() == nums.size()) {
            ans.push_back(cur);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (status & (1 << i)) continue;
            status += 1 << i;
            cur.push_back(nums[i]);
            solve(status, cur, nums, ans);
            status -= 1 << i;
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> cur;
        solve(0, cur, nums, ans);
        return ans;
    }
};
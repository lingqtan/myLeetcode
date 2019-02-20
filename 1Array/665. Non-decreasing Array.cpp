class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size()-1; i++) {
            if (ans >= 2) return false;
            if (i < nums.size()-2 
                && i > 0
                && nums[i] > nums[i+1]
                && nums[i] > nums[i+2]
                && nums[i-1] > nums[i+1]
            ) return false;
            if (nums[i] > nums[i+1]) ans++;
        }
        if (ans >= 2) return false; else return true;
    }
};
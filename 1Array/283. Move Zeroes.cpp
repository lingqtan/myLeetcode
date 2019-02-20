class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // // slow version (16ms, 12.13%)
        // int cur_pos = 0, i = 0;
        // while (cur_pos < nums.size() && i < nums.size()) {
        //     while (nums[cur_pos] != 0 && cur_pos < nums.size()) cur_pos++;
        //     i = cur_pos;
        //     while (nums[i] == 0 && i < nums.size()) i++;
        //     if (cur_pos < nums.size() && i < nums.size()) {
        //         int k = nums[cur_pos];
        //         nums[cur_pos] = nums[i];
        //         nums[i] = k;
        //     }
        // }
        
        // faster version (12ms, 36.57%)
        // int i = 0, j = 1;
        // while (i < nums.size() && j < nums.size()) {
        //     if (nums[i] == 0 && nums[j] != 0 && j > i) {
        //         int k = nums[i];
        //         nums[i] = nums[j];
        //         nums[j] = k;
        //         i++; j++;
        //     }
        //     if (i < nums.size() && nums[i] != 0) i++;
        //     if (nums[i] == 0) {
        //         j = i+1;
        //         while (j < nums.size() && nums[j] == 0) j++;
        //     }
        // }
        
        // fast version (8 ms, 100.00%)
        int i = 0, j = 0;
        for (i = 0; i < nums.size(); i++) 
            if (nums[i] != 0) nums[j++] = nums[i];
        if (j < nums.size())
            for (i = j; i < nums.size(); i++) nums[i] = 0;
    }
};
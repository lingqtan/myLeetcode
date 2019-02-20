class Solution {
const int MAX_NUM = 100000007;
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, int> nums_id_map;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (nums_id_map.count(nums[i]) > 0) {
                nums_id_map[nums[i] + MAX_NUM] = i;            
            }
            else {
                nums_id_map[nums[i]] = i;      
            }
            int a = nums[i];
            int b = target - a;
            if (a != b) {
                std::map<int, int>::iterator itb = nums_id_map.find(b);
                if (itb != nums_id_map.end()) {
                    ans.push_back(i);
                    ans.push_back((*itb).second);
                    break;
                }
            }
            else {
                int b2 = b + MAX_NUM;
                std::map<int, int>::iterator itb = nums_id_map.find(b);
                std::map<int, int>::iterator itb2 = nums_id_map.find(b2);
                if (itb2 != nums_id_map.end() && itb != nums_id_map.end()) {
                    ans.push_back((*itb).second);
                    ans.push_back((*itb2).second);
                    break;
                }                
            }      
        }
        return ans;
    }
};
class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int> > ans;
        for (int i = 0; i < people.size(); i++) ans.push_back(pair(-1, -1));
        std::sort(people.begin(), people.end());
        for(int i = 0; i < people.size(); i++) {
            int h = people[i].first;
            int k = people[i].second;
            int j = 0, shortest_pos = 0;
            while (j < k) { 
                if (ans[shortest_pos].first == -1 || ans[shortest_pos].first >= h) j++;
                shortest_pos++;
            }
            while (ans[shortest_pos].first != -1) shortest_pos++;
            ans[shortest_pos] = pair(h, k);
        }
        return ans;
    }
};
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1 || numRows >= s.size()) return s;
        if (numRows == 2) {
            string ans = "";
            for (int i = 0; i < s.size(); i+=2) ans += s[i];
            for (int i = 1; i < s.size(); i+=2) ans += s[i];
            return ans;
        }
        vector<vector<char> > v;
        for (int i = 0; i < numRows; i++) v.push_back(vector<char>());
        bool zigzag = true;
        int step = 1, pos = 0, t;
        for (int i = 0; i < s.size(); i++) {
            if (zigzag) {
                step = 1, t = numRows;
            }
            else {
                step = -1, t = 0;
            }
            v[pos].push_back(s[i]);
            pos += step;
            if (pos == t) {
                pos = (zigzag) ? numRows-2 : 0;
                zigzag = !zigzag;
            }
        }
        string ans = "";
        for (int i = 0; i < numRows; i++)
            for (int j = 0; j < v[i].size(); j++)
                ans += v[i][j];
        return ans;
    }
};
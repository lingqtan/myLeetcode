class Solution {
    string morseMap[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    unordered_set<string> codeSet;
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            string code;
            for (int j = 0; j < words[i].size(); j++) {
                string morse = morseMap[words[i][j] - 'a'];
                code += morse;
            }
            codeSet.insert(code);
        }
        return codeSet.size();
    }
};
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> m, n; 
        for (char i: s) {
            m[i]++;
        }
        for (char i: t) {
            n[i]++;
        }
        for (char i: t) {
            if (m[i] != n[i])
                return i;
        }
        return '0';
    }
};


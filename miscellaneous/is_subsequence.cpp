class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sl = s.length(), tl = t.length();
        if (tl < sl) return false;
        int temp = 0;
        for (char c: t) {
            if (c == s[temp]) temp++;
            if (temp == sl) return true;
        }
        if (temp == sl) return true;
        return false;
    }
};

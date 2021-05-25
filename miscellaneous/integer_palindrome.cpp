class Solution {
public:
    bool isPalindrome(int x) {
        std::string s = std::to_string(x);
        for (int i=0; i<s.length()/2; ++i) {
            if (s[i] != s[s.length()-i-1]) return false;
        }
        return true;
    }
};

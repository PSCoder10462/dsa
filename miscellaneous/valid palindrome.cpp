class Solution {
public:
    bool isPalindrome(string s) {
        string p;
        for (char x: s) {
            if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') || (x >= '0' && x <= '9'))
                p.push_back(x);
        }
        
        int n = p.length();
        
        for (int i=0; i<n; ++i) {
            if (tolower(p[i]) != tolower(p[n-i-1])) return false;
        }
        return true;
    }
};

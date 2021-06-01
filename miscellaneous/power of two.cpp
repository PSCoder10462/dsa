class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (!n) return false;
        while (n) {
            if (n==1 || n==2) return true;
            if (n%2) return false;
            n /= 2;
        }
        return true;
    }
};

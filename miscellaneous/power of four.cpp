class Solution {
public:
    bool isPowerOfFour(int n) {
        long long p = (long long) pow(4, 16);
        
        if (n <= 0) return false;
        
        int x = log2(n);
        
        cout << x;
        
        if (x % 2 != 0) return false;
        
        return (p % n) ? false : true;
        
    }
};

class Solution {
public:
    std::unordered_map<int, int> m;
    
    int fib(int n) {
        if (m[n]) return m[n];
        
        int a = fib(n-1);
        m[n-1] = a;
        
        int b = fib(n-2);
        m[n-2] = b;
        
        m[n] = a+b;
        
        return m[n];
    }
    
    int climbStairs(int n) {
        m[1] = 1;
        m[2] = 2;
        return fib(n);
    }
};

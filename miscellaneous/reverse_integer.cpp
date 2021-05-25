class Solution {
public:
    int reverse(int x) {
       
        
        long long hi = pow(2, 31) -1;
        long long lo = -pow(2, 31);
        long long t = x;
        
        if (t > hi || t <= lo) return 0;
        
        
        bool neg = x < 0 ? true : false;
        
        if (neg) t = -t;
        
        long long ans = 0;
       
        while (t) {
            ans *= 10;
            if (ans > hi || ans < lo) return 0;
            ans += t % 10;
            t /= 10;
        }
        
        return (neg ? -ans : ans);
        
    }
};

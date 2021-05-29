class Solution {
public:
    int trailingZeroes(int n) {
        if (n<5) return 0;
        // if (n==5) return 1;
        int p = 1;
        for(p; pow(5, p)<=n; ++p);
        p--;
        int ans=0;
        while (p) {
            ans += n/pow(5, p);
            p--;
        }
        return ans;
    }
};

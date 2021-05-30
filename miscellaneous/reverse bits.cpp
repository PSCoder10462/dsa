class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        vector<int> v(32);
        for (int i=0; i<32; ++i) {
            v[i] = (1ll<<i)&n;
        }
        uint32_t ans=0, p2=1;
        
        for (int i=31; i>-1; --i) {
            if (v[i]) 
                ans += p2;
            p2 *= 2;
        }
        
        return ans;
    }
};

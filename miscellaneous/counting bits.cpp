class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        
        for (int i=0; i<=n; ++i) {
            int ctr = 0;
            for (int j=0; j<32; ++j)
                if ((1ll << j) & i) ctr++;
            ans.push_back(ctr);
        }
        
        return ans;
    }
};

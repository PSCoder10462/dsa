class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ctr = 0;
        sort(g.begin(), g.end(), greater<int>());
        sort(s.begin(), s.end(), greater<int>());
        int i, j;
        i = j = 0;
        while (i < g.size() and j < s.size()) {
            if (g[i] <= s[j]) {
                ctr++; j++;
            } 
            ++i;
        }
        return ctr;
    }
};

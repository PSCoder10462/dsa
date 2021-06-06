class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if (n == 1) return 1;
        int start = 0, len = 0;
        unordered_map<char, int> mp;
        mp[s[start]]++;
        for (int j=1; j<n; ++j) {
            mp[s[j]]++;
            while (mp[s[j]] > 1) {
                mp[s[start++]]--;
            }
            len = max(len, j-start+1);
        }
        return len;
    }
};

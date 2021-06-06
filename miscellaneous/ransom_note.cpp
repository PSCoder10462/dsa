class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;
        for (char c: magazine) mp[c]++;
        for (char c: ransomNote) {
            if (!mp[c]) return false;
            mp[c]--;
        }
        return true;
    }
};

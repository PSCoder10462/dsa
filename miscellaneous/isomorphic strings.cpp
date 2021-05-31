class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map <char, char> mp;
        unordered_set<char> st;
        
        int sl = s.length(), tl = t.length();
        
        if (sl != tl) return false;
        
        for (int i=0; i<sl; i++) {
            if (!mp[s[i]] && st.find(t[i])==st.end()) {
                mp[s[i]] = t[i];
                st.insert(t[i]);
            }
            
            if (mp[s[i]] != t[i]) return false;
            
        }
        
        return true;
        
    }
};

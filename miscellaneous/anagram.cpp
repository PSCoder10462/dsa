class Solution {
public:
    bool isAnagram(string s, string t) {
        
        int sl = s.length(), tl = t.length();
        
        if (sl != tl) return false;
        
        vector<int> a(256), b(256);
        
        for (int i=0; i<sl; i++) {
            a[s[i]]++;
            b[t[i]]++;
        }
        
        for (int i=0; i<256; i++)
            if (a[i] != b[i])
                return false;
        
        return true;
        
    }
};

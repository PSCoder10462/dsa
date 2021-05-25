class Solution {
public:
    int strStr(string haystack, string needle) {
        int nl = needle.length();
        int hl = haystack.length();
        
        if (nl<1) return 0;
        
        if (hl < 1 && nl<1) return 0;
        
        if (hl < 1) return -1;
        
        for (int i=0; i<hl-nl+1; ++i) {
            if (haystack.substr(i, nl) == needle) return i;
        }
        
        return -1;
        
    }
};

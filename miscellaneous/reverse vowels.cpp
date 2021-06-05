class Solution {
public:
    
    bool checkVowel (char c) {
        if (c >= 'A' && c <= 'Z') c += 32;
        switch(c) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                return true;
            default: return false;
        }
    }
    
    string reverseVowels(string s) {
        int i=0, j=s.length()-1;
        while (i < j) {
            while (i < j && !checkVowel(s[i])) i++;
            while (i < j && !checkVowel(s[j])) j--;
            swap(s[i], s[j]);
            i++; j--;
        }
        return s;
    }
};

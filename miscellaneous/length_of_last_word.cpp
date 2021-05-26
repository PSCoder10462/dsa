class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.length()<1) return 0;
        
        int ans=0;
        
        int i=s.length()-1;
        
        while (i>=0 && s[i]==' ') --i;
        
        for (i; i>=0 && s[i]!=' '; --i) ans++;
        
        return ans;
    }
};

class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int a = 0, b = 0, c = 0;
        for (char i: firstWord) {
            a += (tolower(i) - 97);
            a *= 10;
        }
        for (char i: secondWord) {
            b += (tolower(i) - 97);
            b *= 10;
        }
        for (char i: targetWord) {
            c += (tolower(i) - 97);
            c *= 10;
        }
        a/=10;
        b/=10;
        c/=10;
        if (a+b == c)
            return true;
        else 
            return false;
    }
};

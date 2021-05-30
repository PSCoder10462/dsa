class Solution {
public:
    bool isHappy(int n) {
        while (n > 9) {
            int temp = n;
            n = 0;
            while (temp) {
                int d = temp%10;
                n += (d*d);
                temp/=10;
            }
        }
        if (n==1 || n==7) return true;
        return false;
    }
};

class Solution {
public:
    int addDigits(int num) {
        while (num/10) {
            int ans = 0;
            int temp = num;
            
            while (temp) {
                ans += temp%10;
                temp/=10;
            }
            
            num = ans;
        }
        
        return num;
    }
};

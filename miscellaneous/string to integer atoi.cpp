class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        long long ans = 0;
        long long pos = pow(2, 31);
        long long ne = -pos;
        pos -= 1;
        bool neg;
        while (i < s.size() and s[i]==' ') i++;
        neg = (s[i] == '-');
        if (neg or s[i] == '+') i++; 
        while (i < s.size() and s[i] >= '0' and s[i] <= '9') {
            ans *= 10;
            ans += (s[i]-'0');
            cout << ans << endl;
            if (neg and -ans <= ne){ cout << "me"; return ne;}
            if ((not neg) and ans >= pos) return pos;
            i++;
        }
        return neg ? -ans : ans;
    }
};

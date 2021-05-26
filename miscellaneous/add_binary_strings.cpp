class Solution {
public:
    string addBinary(string a, string b) {
        
        int al = a.length(), bl = b.length();
        
        std::string ans;
        
        al--; bl--;
        
        int carry = 0;
        
        for (al, bl; al >=0 && bl >= 0; --al, --bl) {
            if (a[al]-'0' + b[bl]-'0' + carry <= 1) { 
                ans.push_back(a[al]-'0' + b[bl] + carry);
                carry = 0;
            }
            else if (a[al]-'0' + b[bl]-'0' + carry == 2) {
                ans.push_back('0');
                carry=1;
            } else {
                ans.push_back('1');
                carry = 1;
            }   
        }
        
        
        while (al >= 0) {
            if (a[al]-'0' + carry <= 1) { 
                ans.push_back(a[al] + carry);
                carry = 0;
            }
            else if (a[al] -'0' + carry == 2) {
                ans.push_back('0');
                carry=1;
            } else {
                ans.push_back('1');
                carry = 1;
            }
            al--;
        }
        
        while (bl >= 0) {
            if (b[bl]-'0' + carry <= 1) { 
                ans.push_back(b[bl] + carry);
                carry = 0;
            }
            else if (b[bl]- '0' + carry == 2) {
                ans.push_back('0');
                carry=1;
            } else {
                ans.push_back('1');
                carry = 1;
            }
            
            bl--;
        }
        
        std::reverse(ans.begin(), ans.end());
        
        if (carry == 1) ans.insert(0, "1");
        
        return ans;
        
    }
};

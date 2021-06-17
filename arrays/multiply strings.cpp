#include <algorithm>
string multiplyStrings(string a , string b ){
    
        string ans;
         
        int ctr = 0;
        
        for (int j = b.length()-1; j>=0; --j) {
        
            int carry = 0, anspos = 0;
            int jn = b[j]-'0';
            anspos = ctr++;
            
            for (int i=a.length()-1; i>=0; --i) {
                
                int in = a[i]-'0';
                
                int multi = (in*jn)+carry;
                
                if (ans.length() == anspos) 
                    ans.push_back('0');
                    
                multi += (ans[anspos]-'0');

                carry = multi / 10;

                ans[anspos++] = (multi % 10) + '0';
                
            }
            
            if (carry != 0)
                ans.push_back(carry+'0');
        
        }
        
        for (char c : ans) if (c != '0') {
        
            std::reverse(ans.begin(), ans.end());
        
            return ans;
        }
        
        return "0";
 
}

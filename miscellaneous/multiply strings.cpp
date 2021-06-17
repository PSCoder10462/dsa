class Solution {
public:
    string multiply(string num1, string num2) {
        
        string ans;
         
        int ctr = 0;
        
        for (int j = num2.length()-1; j>=0; --j) {
        
            int carry = 0, anspos = 0;
            int jn = num2[j]-'0';
            anspos = ctr++;
            
            for (int i=num1.length()-1; i>=0; --i) {
                
                int in = num1[i]-'0';
                
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
        
            reverse(ans.begin(), ans.end());
        
            return ans;
        }
        
        return "0";
    }
};

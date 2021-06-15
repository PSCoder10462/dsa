class Solution {
public:
    unordered_map <int, string> mp;
    
    string f(int n) {
        // base case
        if (mp[n] != "") return mp[n];
        
        string temp = mp[n-1];
        
        if (temp == "") {
            temp = f(n-1);
            mp[n-1] = temp;
        } 
        
        string ans = "";
        
        for (int i=0; i<temp.length(); ++i) {
            int ctr = 0; char c = temp[i];
            for (int j=i; j<temp.length() and temp[i]==temp[j]; ++j) {
                ctr++;
            }
            i += ctr-1;
            ans += to_string(ctr);
            ans.push_back(c);
        }
        
        cout << "temp: " << temp << " ans: " << ans << endl;
        
        return ans;
        
    }
    
    string countAndSay(int n) {
        mp[1] = "1";
        return f(n);
    }
};

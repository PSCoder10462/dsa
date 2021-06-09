class Solution {
public:
    
    vector <char> 
        two     {'a', 'b', 'c'},
        three   {'d', 'e', 'f'},
        four    {'g', 'h', 'i'},
        five    {'j', 'k', 'l'},
        six     {'m', 'n', 'o'},
        seven   {'p', 'q', 'r', 's'},
        eight   {'t', 'u', 'v'},
        nine    {'w', 'x', 'y', 'z'};
    
    map <char, vector<char>> mp;
    
    vector <string> cp (vector<string> &a, vector<char> &b) {
        
        int as = a.size(), bs = b.size();
        
        vector <string> ans;

        if (as == 0) {
            for (char bs: b) {
                string temp; temp.push_back(bs);
                ans.push_back(temp);
            }
        }
        
        
        for (string as : a) {
            for (char bs: b) {
                string temp; temp.push_back(bs);
                ans.push_back(as + temp);
            }
        }
        
        return ans;
        
    }
    
    
    vector<string> letterCombinations(string digits) {
        
        mp.clear();
        
        mp.insert(make_pair('2', two));
        mp.insert(make_pair('3', three));
        mp.insert(make_pair('4', four));
        mp.insert(make_pair('5', five));
        mp.insert(make_pair('6', six));
        mp.insert(make_pair('7', seven));
        mp.insert(make_pair('8', eight));
        mp.insert(make_pair('9', nine));
        
        vector<string> ans;
        
        for (char c : digits) {
            ans = cp(ans, mp[c]);
        }
        
        return ans;
    }
};

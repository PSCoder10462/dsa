class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        std::vector<int> v,w={1};
        
        if (digits.size()<1) return v;
        
        v.insert(v.end(), digits.begin(), digits.end());
        
        int carry = 1;
        
        for (int i=v.size()-1; i>=0; --i) {
            if (v[i] == 9) v[i] = 0;
            else {
                v[i]++;
                return v;
            }
            w.push_back(0);
        }
        return w;
    }
};

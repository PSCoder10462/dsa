class Solution {
public:
    vector<string> ans;
    set <string> st;
    
    void f(int i, int n, string osf) {
        
        if (i == n) {
            if (st.find(osf) != st.end()) return;
            ans.push_back(osf);
            st.insert(osf);
            return ;
            
        }
            
        
        if (i == 0) f(1, n, "()");
        else {
            set <string> temp;
            for (int j=0; j<osf.length(); ++j) {
                string s = "(" + osf.substr(0, j) + ")" + osf.substr(j);
                cout << osf << " " << s << endl;
                if (temp.find(s) == temp.end()){
                    f(i+1, n, s);
                    temp.insert(s);
                }
            }
        }
        
    }
    
    vector<string> generateParenthesis(int n) {
        ans.clear();
        st.clear();
        f(0, n, "");
        sort(ans.begin(), ans.end());
        return ans;
    }
};

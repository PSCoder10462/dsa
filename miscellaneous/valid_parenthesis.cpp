class Solution {
public:
    bool isValid(string s) {
        std::stack <char> st;
        for (char x: s) {
            switch(x) {
                case '(': st.push(x);
                    break;
                case '{': st.push(x);
                    break;
                case '[': st.push(x);
                    break;
                case ')': if (st.empty() || st.top() != '(') return false;
                    st.pop();
                    break;
                case '}': if (st.empty() || st.top() != '{') return false;
                    st.pop();
                    break;
                case ']': if (st.empty() || st.top() != '[') return false;
                    st.pop();
                    break;
            }
        }
        if (!st.empty()) return false;
        return true;
    }
};

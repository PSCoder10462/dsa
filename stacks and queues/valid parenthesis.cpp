#include <stack>

bool isValidParenthesis(string expression)
{
    // Write your code here.
	stack <char> st;
    for (char c: expression) {
        if (c == '(' or c == '{' or c == '[') st.push(c);
        switch(c) {
            case ')': if (st.empty() or st.top()!='(') return false;
                st.pop();
             	break;
            case '}': if (st.empty() or st.top()!='{') return false;
                st.pop();
             	break;
            case ']': if (st.empty() or st.top()!='[') return false;
                st.pop();
             	break;
            default: continue;
        } 
    }
   	if (st.empty()) return true;
    return false;
}

#include <stack>

bool checkValidString(string &s){
	stack<int> op, st;
    for (int i=0; i < s.length(); ++i) {
        char c = s[i];
        switch(c) {
            case '(' : op.push(i);
                break;
            case '*' : st.push(i);
                break;
            case ')' : {
                if (!op.empty()) op.pop();
                else if (!st.empty()) st.pop();
                else return false;
            }
        }
    }
    
    if (op.size() > st.size()) return false;
   
    while (!op.empty()) {
        if (op.top() > st.top()) return false;
        op.pop(); st.pop();
    }
    
    return true;
}

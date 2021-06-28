void f (stack<int>&stack, int t) {
    if (stack.empty()) {
        stack.push(t);
        return;
    }
    int a = stack.top();
    stack.pop();
    f(stack, t);
    stack.push(a);
}


void reverseStack(stack<int> &stack) {
    // Write your code here
    if (stack.empty()) return;
    int t=stack.top();
    stack.pop();
    reverseStack(stack);
    f(stack, t);
}

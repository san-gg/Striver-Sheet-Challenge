void stackInsert(stack<int> &stack, int n) {
    if(stack.empty() || stack.top() <= n) {
        stack.push(n);
        return;
    }
    int num = stack.top();
    stack.pop();
    stackInsert(stack, n);
    stack.push(num);
    return;
}

void sortStack(stack<int> &stack)
{
    if(stack.empty()) return;
    int num = stack.top();
    stack.pop();
    sortStack(stack);
    stackInsert(stack, num);
    return;
}
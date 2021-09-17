#include <queue>
int weightOfLastStone(int arr[], int n)
{
    // Write your Code here
    priority_queue<int> Q;
    for (int i=0; i<n; ++i) {
        Q.push(arr[i]);
    }
    while (Q.size() > 1) {
        int w1 = Q.top(); Q.pop();
        int w2 = Q.top(); Q.pop();
        int w3 = abs(w2-w1);
        if (w3 > 0) Q.push(w3);
    }
    return Q.empty() ? 0 : Q.top();
}

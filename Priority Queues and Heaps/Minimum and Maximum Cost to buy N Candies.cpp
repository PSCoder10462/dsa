#include <queue>
#include <math.h>
// Function to calculate minimum cost.
long long minimumCost(vector<int> &cost, int n, int k)
{
    // Write your code here.
    int N = ceil(float(n)/(k+1.0));
    
    // max heap
    priority_queue<int> Q;
    for (int i=0; i<n; ++i) {
        if (i<N) Q.push(cost[i]);
        else {
            if (Q.top() > cost[i]) {
                Q.pop(); Q.push(cost[i]);
            }
        }
    }
    
    long long ans = 0;
    while (!Q.empty()) {
        ans += Q.top(); Q.pop();
    }
    
    return ans;
}

// Function to calculate maximum cost.
long long maximumCost(vector<int> &cost, int n, int k)
{
    // Write your code here.
    int N = ceil((float)n/(k+1.0));
    
    // min heap
    priority_queue<int, vector<int>, greater<int>> Q;
    for (int i=0; i<n; ++i) {
        if (i<N) Q.push(cost[i]);
        else {
            if (Q.top() < cost[i]) {
                Q.pop(); Q.push(cost[i]);
            }
        }
    }
    
    long long ans = 0;
    while (!Q.empty()) {
        ans += Q.top(); Q.pop();
    }
    
    return ans;
}

#include <queue>
#define ll long long

long long connectRopes(int* arr, int n)
{
    // Your code goes here
	priority_queue<ll, vector<ll>, greater<ll>> Q;
    for (int i=0; i<n; ++i) Q.push(arr[i]);
	ll cost = 0ll;
    while (Q.size() > 1) {
        ll a = Q.top(); Q.pop();
        ll b = Q.top(); Q.pop();
    	cost += (a+b);
        Q.push(a+b);
    }
    return cost;
}

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>> &adj, int V, vector<bool> &vis) {
    queue<int> q;
    q.push(0);
    vis[0] = true;
    while (!q.empty()) {
        int temp = q.front(); q.pop();
        for (int i: adj[temp]) {
            if (!vis[i]) {
                vis[i] = true;
                q.push(i);
            }
        }
    }
}

bool isTree(vector<vector<int>> &adj, int V, int e)
{
    // Write your code here.
    if (e != V-1) return false;

    vector<bool> vis(V, false);
    
    bfs(adj, V, vis);
    
    for (bool b: vis)
        if (!b) return b;
    
    return true;
    
}

// Do not change this part of the code. You only need to complete the isTree function above.
int main()
{
    int v, e;
    cin >> v >> e;

    vector<vector<int>> adj(v);

    for (int i = 0, a, b; i < e; ++i)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if (isTree(adj, v, e))
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }

    return 0;
}

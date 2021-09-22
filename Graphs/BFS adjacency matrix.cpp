// 1 based indexing
void bfs(vvb &adj, int V, vb &visited, int starter = 1) {
    queue<int> q;
    cout << starter << ' ';
    visited[starter] = true;
    q.push(starter);
    while (!q.empty()) {
        int node = q.front(); q.pop();
        loop(i, 0, V) 
            if (adj[node][i] and !visited[i]) {
                q.push(i);         
                cout << i <<  ' ';
                visited[i] = true;
            }
    }
}

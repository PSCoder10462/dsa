#include <bits/stdc++.h>
using namespace std;
#define vb                vector<bool>
#define vi                vector<int>
#define umii              unordered_map<int, int>
#define loop(i, a, b)     for (int i = a; i <= b; ++i)

int findHeight(int n, vi &lo, umii &mp) {
  if (n <= 1) return 0;
  vb visited(n, false); 
  int height = 0;
  queue <int> q1, q2;
  int t = 1;
  q1.push(lo[0]);
  while (!q1.empty() or !q2.empty()) {
    while (!q1.empty()) {
      int node = q1.front();
      q1.pop();
      int ind = mp[node];
      visited[ind] = true;
      if (t < n and ind == 0 and !visited[1]) q2.push(lo[t++]);
      else if (t < n and ind == n-1 and !visited[n-2]) q2.push(lo[t++]);
      else if (t < n and (ind > 0 and ind < n-1)){
          if (!visited[ind-1] and !visited[ind+1]) {
        	q2.push(lo[t++]); 
        	q2.push(lo[t++]);   
          } else if (!visited[ind-1] or !visited[ind+1])
        	q2.push(lo[t++]);
      }
    }
    if (!q2.empty()) height++;
    while (!q2.empty()) {
      int node = q2.front();
      q2.pop();
      int ind = mp[node];
      visited[ind] = true;
      if (t < n and ind == 0 and !visited[1]) q1.push(lo[t++]);
      else if (t < n and ind == n-1 and !visited[n-2]) q1.push(lo[t++]);
       else if (t < n and (ind > 0 and ind < n-1)){
          if (!visited[ind-1] and !visited[ind+1]) {
        	q1.push(lo[t++]); 
        	q1.push(lo[t++]);   
          } else if (!visited[ind-1] or !visited[ind+1])
        	q1.push(lo[t++]);
      }
    }
    if (!q1.empty()) height++;
  }

  return height;
}

int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder, int N){
	// Write your code here.
  umii mp;
  loop (i, 0, N-1) mp[inorder[i]] = i;
  return findHeight(N, levelOrder, mp);
}

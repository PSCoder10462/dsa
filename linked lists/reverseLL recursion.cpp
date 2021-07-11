#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define mid(l, h) ((l + h) / 2)
#define loop(i, a, b) for (int i = a; i <= b; ++i)
#define looprev(i, a, b) for (int i = a; i >= b; --i)
#define mod(a) (a % 100'000'007)
#define endl '\n'

void file_i_o() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}

// node of LL
class Node {
 public:
  int val;
  Node *next;

  Node(int v) {
    val = v;
    next = nullptr;
  }

  Node(int v, Node *n) {
    val = v;
    next = n;
  }
};

// prints LL
void printLL(Node *&head) {
  for (Node *ptr = head; ptr != nullptr; ptr = ptr->next) {
    cout << ptr->val;
    if (ptr->next) cout << " -> ";
  }
}

// recursively reverse LL
Node *reverseLL(Node *head) {
  if (!head or !head->next) return head;

  Node *rest = reverseLL(head->next);

  head->next->next = head;

  head->next = nullptr;

  return rest;
}

void solve() {
  // creating ll
  int n;
  cin >> n;
  Node *head, *ptr, *lst;
  head = ptr = lst = nullptr;
  loop(i, 1, n) {
    int v;
    cin >> v;
    ptr = new Node(v);
    if (!head) {
      head = lst = ptr;
    } else {
      lst->next = ptr;
      lst = lst->next;
    }
    ptr = nullptr;
  }

  // print LL
  printLL(head);
  Node *temp = reverseLL(head);

  // print reversed LL
  cout << endl;
  printLL(temp);
}

int32_t main() {
  clock_t start = clock();
  file_i_o();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
#ifndef ONLINE_JUDGE
  clock_t end = clock();
  cout << "\n\nExecuted in: " << (double)(end - start) / double(CLOCKS_PER_SEC)
       << " sec";
#endif
  return 0;
}

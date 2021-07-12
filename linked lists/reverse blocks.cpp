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

class Node {
 public:
  int data;
  Node *next;
  Node(int n) {
    this->data = n;
    this->next = nullptr;
  }
};

void createNode(Node *&head, Node *&last, int n) {
  if (!head) {
    head = new Node(n);
    last = head;
  } else {
    last->next = new Node(n);
    last = last->next;
  }
}

void printLL(Node *&head) {
  for (Node *ptr = head; ptr != nullptr; ptr = ptr->next) {
    cout << ptr->data;
    if (ptr->next) cout << "->";
  }
}

Node *reverseLL(Node *head) {
  if (not head or not head->next) return head;

  Node *rest = reverseLL(head->next);

  head->next->next = head;

  head->next = nullptr;

  return rest;
}

void solve() {
  int n;
  cin >> n;

  Node *head, *last;

  head = last = nullptr;

  while (n != -1) {
    createNode(head, last, n);
    cin >> n;
  }

  cin >> n;

  vi b(n);

  loop(i, 0, n - 1) cin >> b[i];

  printLL(head);
  cout << endl;

  if (not head or not head->next) return;

  Node *ptr = head, *nhead = nullptr;

  Node *temp = head, *start = head;
  loop(i, 0, n - 1) {
    if (not b[i]) continue;
    if (not start) break;
    ptr = start;
    loop(j, 1, b[i] - 1) {
      if (not ptr->next) break;
      ptr = ptr->next;
    }
    if (not ptr) break;
    temp = ptr->next;
    ptr->next = nullptr;
    ptr = reverseLL(start);
    start = temp;
    if (not nhead) {
      nhead = ptr;
      last = nhead;
    } else
      last->next = ptr;
    while (last->next) last = last->next;
  }

  last->next = start;

  printLL(nhead);
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

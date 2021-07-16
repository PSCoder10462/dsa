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
    data = n;
    next = nullptr;
  }
};

void createNode(Node *&head, Node *&last, int n) {
  Node *ptr = new Node(n);
  if (not head) {
    head = last = ptr;
  } else {
    last->next = ptr;
    last = ptr;
  }
}

void printLL(Node *head) {
  while (head) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

Node *mergeLL(Node *f, Node *s) {
  Node *ans = nullptr, *last = nullptr;
  while (f and s) {
    if (f->data <= s->data) {
      createNode(ans, last, f->data);
      f = f->next;
    } else {
      createNode(ans, last, s->data);
      s = s->next;
    }
  }
  while (f) {
    createNode(ans, last, f->data);
    f = f->next;
  }
  while (s) {
    createNode(ans, last, s->data);
    s = s->next;
  }
  return ans;
}

Node *qcksrt(Node *head) {
  // base
  if (not head or not head->next) return head;

  // divide
  Node *p, *c, *prev = nullptr;

  p = c = head;

  while (c->next) {
    if (c->next->data >= p->data) {
      c = c->next;
      continue;
    }
    if (prev) {
      prev->next = c->next;
      c->next = c->next->next;
      prev = prev->next;
      prev->next = p;
    } else {
      prev = c->next;
      c->next = prev->next;
      prev->next = p;
      head = prev;
    }
  }

  if (prev) {
    prev->next = nullptr;
  } else {
    Node *rest = qcksrt(head->next);
    head->next = rest;
    return head;
  }
  // conquer
  Node *y = qcksrt(head), *z = qcksrt(p);

  return mergeLL(y, z);
}

void solve() {
  Node *head, *last;
  head = last = nullptr;
  int n;
  cin >> n;
  while (n != -1) {
    createNode(head, last, n);
    cin >> n;
  }
  printLL(qcksrt(head));
}

int32_t main() {
  clock_t start = clock();
  file_i_o();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
#ifndef ONLINE_JUDGE
  clock_t end = clock();
  cout << "\n\nExecuted in: " << (double)(end - start) / double(CLOCKS_PER_SEC)
       << " sec";
#endif
  return 0;
}
